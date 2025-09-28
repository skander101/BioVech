import cv2
import numpy as np
import face_recognition
import sys
import os
import json
import base64
import time
import select

class FaceRecognitionModule:
    def __init__(self):
        self.camera = None
        self.known_face_encodings = []
        self.known_face_ids = []
        self.last_debug_time = time.time()
        self.load_known_faces()

    def debug_print(self, message):
        """Controlled debug output"""
        current_time = time.time()
        if current_time - self.last_debug_time > 0.1:
            print(f"DEBUG: {message}")
            sys.stdout.flush()
            self.last_debug_time = current_time

    def load_known_faces(self):
        """Load known faces from JSON file"""
        try:
            if not os.path.exists('face_data.json'):
                self.debug_print("No face_data.json found - will create when needed")
                return

            with open('face_data.json', 'r') as f:
                data = json.load(f)
                for face_id, face_data in data.items():
                    try:
                        face_bytes = base64.b64decode(face_data)
                        face_array = np.frombuffer(face_bytes, dtype=np.float64)
                        self.known_face_encodings.append(face_array)
                        self.known_face_ids.append(face_id)
                    except Exception as e:
                        self.debug_print(f"Error loading face {face_id}: {str(e)}")

            self.debug_print(f"Loaded {len(self.known_face_ids)} known faces")
        except Exception as e:
            self.debug_print(f"Error loading face data: {str(e)}")

    def save_face_data(self, face_id, face_encoding):
        """Save face data to JSON file"""
        try:
            data = {}
            if os.path.exists('face_data.json'):
                with open('face_data.json', 'r') as f:
                    data = json.load(f)

            face_bytes = face_encoding.tobytes()
            face_base64 = base64.b64encode(face_bytes).decode('utf-8')
            data[face_id] = face_base64

            with open('face_data.json', 'w') as f:
                json.dump(data, f)

            self.debug_print(f"Saved face data for ID: {face_id}")
            return True
        except Exception as e:
            self.debug_print(f"Failed to save face data: {str(e)}")
            return False

    def start_camera(self):
        """Main camera capture loop"""
        self.debug_print("Starting camera...")

        try:
            self.camera = cv2.VideoCapture(0)
            if not self.camera.isOpened():
                self.debug_print("Could not open camera")
                return False

            # Set camera properties
            self.camera.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
            self.camera.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
            self.camera.set(cv2.CAP_PROP_FPS, 30)

            self.debug_print("Camera started successfully")
            frame_count = 0
            last_frame_time = time.time()
            last_command_check = time.time()
            frame_interval = 1.0 / 5.0  # 5 FPS
            command_check_interval = 0.1  # Check for commands every 100ms

            # Buffer for collecting command input
            command_buffer = ""
            
            while True:
                # Check for direct command input first
                try:
                    if sys.stdin in select.select([sys.stdin], [], [], 0)[0]:
                        command = sys.stdin.readline().strip()
                        if command:
                            self.debug_print(f"Received direct command: {command}")
                            sys.stdout.flush()
                            
                            if command == "capture":
                                ret, frame = self.camera.read()
                                if ret:
                                    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                                    face_locations = face_recognition.face_locations(rgb_frame)
                                    face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)
                                    self.handle_capture(face_locations, face_encodings)
                            elif command == "verify":
                                ret, frame = self.camera.read()
                                if ret:
                                    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                                    face_locations = face_recognition.face_locations(rgb_frame)
                                    face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)
                                    self.handle_verify(face_locations, face_encodings)
                            elif command == "stop":
                                self.debug_print("Stop command received, shutting down")
                                sys.stdout.flush()
                                break
                except Exception as e:
                    self.debug_print(f"Command check error: {str(e)}")
                
                # Read and process camera frame
                ret, frame = self.camera.read()
                if not ret:
                    self.debug_print("Failed to capture frame")
                    time.sleep(0.1)
                    continue

                current_time = time.time()
                if current_time - last_frame_time < frame_interval:
                    continue

                frame_count += 1
                if frame_count % 2 != 0:
                    continue

                # Process frame
                rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                small_frame = cv2.resize(rgb_frame, (0, 0), fx=0.5, fy=0.5)

                face_locations = face_recognition.face_locations(small_frame, model="hog")
                face_encodings = face_recognition.face_encodings(rgb_frame,
                    [(top*2, right*2, bottom*2, left*2) for (top, right, bottom, left) in face_locations])

                # Draw rectangles
                for (top, right, bottom, left) in face_locations:
                    cv2.rectangle(frame, (left*2, top*2), (right*2, bottom*2), (0, 255, 0), 2)

                # Send frame to UI
                self.send_frame_to_ui(frame)
                last_frame_time = current_time

                # Process commands using the enhanced method
                self.process_commands(face_locations, face_encodings)

        except KeyboardInterrupt:
            self.debug_print("Camera loop stopped by keyboard interrupt")
        except Exception as e:
            self.debug_print(f"Camera error: {str(e)}")
        finally:
            self.stop_camera()
        return True

    def send_frame_to_ui(self, frame):
        """Send frame to Qt application"""
        try:
            _, buffer = cv2.imencode('.jpg', frame, [cv2.IMWRITE_JPEG_QUALITY, 85])
            frame_bytes = buffer.tobytes()
            print(f"FRAME:{frame_bytes.hex()}")
            sys.stdout.flush()
        except Exception as e:
            self.debug_print(f"Failed to send frame: {str(e)}")

    def process_commands(self, face_locations, face_encodings):
        """Process commands from Qt application"""
        try:
            # Read from stdin directly without any fancy techniques
            # Qt will write commands directly to the process
            command = None
            
            # Read any available input without blocking
            if sys.stdin.readline().strip():
                command = sys.stdin.readline().strip()
            
            if command:
                self.debug_print(f"Received command: {command}")
                sys.stdout.flush()
                
                if command == "capture":
                    self.handle_capture(face_locations, face_encodings)
                elif command == "verify":
                    self.handle_verify(face_locations, face_encodings)
                elif command == "stop":
                    self.debug_print("Received stop command, stopping camera")
                    sys.stdout.flush()
                    raise KeyboardInterrupt
        except Exception as e:
            self.debug_print(f"Command read error: {str(e)}")
            sys.stdout.flush()

    def handle_capture(self, face_locations, face_encodings):
        """Handle face capture command"""
        self.debug_print("Processing capture command...")
        sys.stdout.flush()
        
        # Attempt multiple captures to ensure we detect a face
        max_attempts = 10
        for attempt in range(max_attempts):
            self.debug_print(f"Face detection attempt {attempt+1}/{max_attempts}")
            sys.stdout.flush()
            
            # Capture a new frame
            ret, frame = self.camera.read()
            if not ret:
                continue
            
            # Convert to RGB for face_recognition
            rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            
            # Try different scales for better face detection
            scales = [1.0, 0.75, 0.5]
            detected_face = False
            
            for scale in scales:
                if detected_face:
                    break
                    
                # Resize frame based on scale
                if scale != 1.0:
                    small_frame = cv2.resize(rgb_frame, (0, 0), fx=scale, fy=scale)
                else:
                    small_frame = rgb_frame
                
                # Detect faces - try both HOG (faster) and CNN (more accurate) models
                face_locations_scale = face_recognition.face_locations(small_frame, model="hog")
                
                if not face_locations_scale and scale == 1.0:  # Only try CNN on full resolution as it's slower
                    try:
                        self.debug_print("Trying CNN model for better face detection")
                        face_locations_scale = face_recognition.face_locations(small_frame, model="cnn")
                    except:
                        self.debug_print("CNN model not available, continuing with HOG")
                
                if face_locations_scale:
                    # Found faces at this scale
                    self.debug_print(f"Detected {len(face_locations_scale)} faces at scale {scale}")
                    
                    # Adjust face locations back to original scale if needed
                    if scale != 1.0:
                        face_locations_orig = []
                        for (top, right, bottom, left) in face_locations_scale:
                            face_locations_orig.append((
                                int(top / scale),
                                int(right / scale),
                                int(bottom / scale),
                                int(left / scale)
                            ))
                        face_locations = face_locations_orig
                    else:
                        face_locations = face_locations_scale
                    
                    # Get face encodings
                    face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)
                    
                    if face_encodings:
                        detected_face = True
                        break
            
            if detected_face:
                break
            
            # Wait a bit before next attempt
            time.sleep(0.2)
        
        # After all attempts, check if we found a face
        if not face_locations or not face_encodings:
            print("ERROR: No face detected after multiple attempts")
            sys.stdout.flush()
            return
        
        try:
            # Take the first face encoding (if multiple faces, use the first one)
            face_encoding = face_encodings[0]
            face_bytes = face_encoding.tobytes()
            
            # Draw rectangle around the detected face and display it
            (top, right, bottom, left) = face_locations[0]
            cv2.rectangle(frame, (left, top), (right, bottom), (0, 255, 0), 2)
            
            # Add text to indicate successful detection
            cv2.putText(frame, "Face Detected", (left, top - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
            
            # Send this frame to the UI to show the user which face was captured
            _, buffer = cv2.imencode('.jpg', frame, [cv2.IMWRITE_JPEG_QUALITY, 85])
            frame_bytes = buffer.tobytes()
            print(f"FRAME:{frame_bytes.hex()}")
            
            # Send face code
            print(f"FACE_CODE:{face_bytes.hex()}")
            sys.stdout.flush()
            
            # Save to file for verification later
            with open("stored_face.txt", "wb") as f:
                f.write(face_bytes)
            self.debug_print("Face encoding saved to stored_face.txt")
            sys.stdout.flush()
        except Exception as e:
            print(f"ERROR: Capture failed: {str(e)}")
            sys.stdout.flush()

    def handle_verify(self, face_locations, face_encodings):
        """Handle face verification command"""
        self.debug_print("Processing verify command...")
        sys.stdout.flush()
        
        # Check if we have a stored face to verify against
        if not os.path.exists("stored_face.txt"):
            print("ERROR: No stored face found for verification")
            print("VERIFY_RESULT:false")
            sys.stdout.flush()
            return
        
        # Load the stored face
        try:
            with open("stored_face.txt", "rb") as f:
                stored_bytes = f.read()
                stored_encoding = np.frombuffer(stored_bytes, dtype=np.float64)
        except Exception as e:
            print(f"ERROR: Failed to load stored face: {str(e)}")
            print("VERIFY_RESULT:false")
            sys.stdout.flush()
            return
        
        # Attempt multiple captures to ensure we detect a face
        max_attempts = 10
        for attempt in range(max_attempts):
            self.debug_print(f"Face verification attempt {attempt+1}/{max_attempts}")
            sys.stdout.flush()
            
            # Capture a new frame
            ret, frame = self.camera.read()
            if not ret:
                continue
            
            # Convert to RGB for face_recognition
            rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            
            # Try different scales for better face detection
            scales = [1.0, 0.75, 0.5]
            detected_face = False
            
            for scale in scales:
                if detected_face:
                    break
                    
                # Resize frame based on scale
                if scale != 1.0:
                    small_frame = cv2.resize(rgb_frame, (0, 0), fx=scale, fy=scale)
                else:
                    small_frame = rgb_frame
                
                # Detect faces - try both HOG (faster) and CNN (more accurate) models
                face_locations_scale = face_recognition.face_locations(small_frame, model="hog")
                
                if not face_locations_scale and scale == 1.0:  # Only try CNN on full resolution as it's slower
                    try:
                        self.debug_print("Trying CNN model for better face detection")
                        face_locations_scale = face_recognition.face_locations(small_frame, model="cnn")
                    except:
                        self.debug_print("CNN model not available, continuing with HOG")
                
                if face_locations_scale:
                    # Found faces at this scale
                    self.debug_print(f"Detected {len(face_locations_scale)} faces at scale {scale}")
                    
                    # Adjust face locations back to original scale if needed
                    if scale != 1.0:
                        face_locations_orig = []
                        for (top, right, bottom, left) in face_locations_scale:
                            face_locations_orig.append((
                                int(top / scale),
                                int(right / scale),
                                int(bottom / scale),
                                int(left / scale)
                            ))
                        face_locations = face_locations_orig
                    else:
                        face_locations = face_locations_scale
                    
                    # Get face encodings
                    face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)
                    
                    if face_encodings:
                        detected_face = True
                        break
            
            if detected_face:
                break
            
            # Wait a bit before next attempt
            time.sleep(0.2)
        
        # After all attempts, check if we found a face
        if not face_locations or not face_encodings:
            print("ERROR: No face detected for verification after multiple attempts")
            print("VERIFY_RESULT:false")
            sys.stdout.flush()
            return
        
        try:
            # Take the first face encoding (if multiple faces, use the first one)
            face_encoding = face_encodings[0]
            
            # Compare faces with appropriate tolerance levels
            # Try multiple tolerance levels for better accuracy
            tolerance_levels = [0.5, 0.55, 0.6, 0.65]
            match_results = []
            
            for tolerance in tolerance_levels:
                matches = face_recognition.compare_faces([stored_encoding], face_encoding, tolerance=tolerance)
                match_results.append(matches[0])
                self.debug_print(f"Match at tolerance {tolerance}: {matches[0]}")
            
            # Determine final result (majority vote)
            match_count = sum(1 for m in match_results if m)
            result = match_count > len(tolerance_levels) / 2
            
            # Calculate face distance (lower is better match)
            face_distances = face_recognition.face_distance([stored_encoding], face_encoding)
            distance = face_distances[0] if len(face_distances) > 0 else 1.0
            
            self.debug_print(f"Face distance: {distance}, Final result: {result}")
            
            # Draw rectangle around the detected face with color based on match
            (top, right, bottom, left) = face_locations[0]
            color = (0, 255, 0) if result else (0, 0, 255)  # Green if match, red otherwise
            cv2.rectangle(frame, (left, top), (right, bottom), color, 2)
            
            # Add text to indicate verification result
            result_text = "Verified" if result else "Not Verified"
            cv2.putText(frame, result_text, (left, top - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, color, 2)
            
            # Add face distance score
            score_text = f"Score: {1.0 - distance:.2f}"
            cv2.putText(frame, score_text, (left, bottom + 25), cv2.FONT_HERSHEY_SIMPLEX, 0.7, color, 2)
            
            # Send this frame to the UI to show the verification result
            _, buffer = cv2.imencode('.jpg', frame, [cv2.IMWRITE_JPEG_QUALITY, 85])
            frame_bytes = buffer.tobytes()
            print(f"FRAME:{frame_bytes.hex()}")
            
            # Send verification result
            final_result = "true" if result else "false"
            print(f"VERIFY_RESULT:{final_result}")
            sys.stdout.flush()
        except Exception as e:
            print(f"ERROR: Verification failed: {str(e)}")
            print("VERIFY_RESULT:false")
            sys.stdout.flush()

    def stop_camera(self):
        """Release camera resources"""
        if self.camera is not None:
            self.camera.release()
            self.camera = None
            self.debug_print("Camera released")

def main():
    try:
        if len(sys.argv) > 1 and sys.argv[1] == "--start-camera":
            print("DEBUG: Starting face recognition module")
            sys.stdout.flush()
            module = FaceRecognitionModule()
            module.start_camera()
        else:
            print("Usage: python face_recognition_module.py --start-camera")
    except Exception as e:
        print(f"ERROR: Fatal error: {str(e)}")
        sys.stdout.flush()

if __name__ == "__main__":
    main()
