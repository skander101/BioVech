#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Bridge script to connect Qt application with face recognition functionality.
This script provides a simple interface for:
1. Capturing faces from webcam
2. Generating face embeddings
3. Verifying faces against stored embeddings
4. All with JSON output for easy integration with Qt

Usage:
  python face_recognition_bridge.py --capture-facecode --id 123
  python face_recognition_bridge.py --verify-face --image path/to/image.jpg --id 123
"""

import os
import sys
import json
import tempfile
import argparse
import cv2
import base64
from pathlib import Path

# Import face recognition module
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.append(script_dir)
import face_recognition as fr

# Database functions
def get_facecode_from_db(employee_id, db_file=None):
    """
    Get facecode from database or from file storage.
    Attempts multiple methods to fetch the face embedding:
    1. First checks JSON files in the facecodes directory (for testing/fallback)
    2. Then tries to read from a facecodes.json file with all IDs 
    """
    employee_id = str(employee_id).strip()
    print(f"Looking for face code for employee ID: {employee_id}")
    
    # Method 1: Look for individual JSON file with the employee ID
    facecode_dir = os.path.join(script_dir, "facecodes")
    os.makedirs(facecode_dir, exist_ok=True)
    
    facecode_file = os.path.join(facecode_dir, f"{employee_id}.json")
    print(f"Checking for individual face code file: {facecode_file}")
    
    if os.path.exists(facecode_file):
        try:
            print(f"Found individual face code file for ID {employee_id}")
            with open(facecode_file, 'r') as f:
                data = json.load(f)
                if 'face_embedding' in data:
                    print("Successfully loaded face embedding from file")
                    return data.get('face_embedding')
        except Exception as e:
            print(f"Error reading individual face code file: {str(e)}")
    
    # Method 2: Look for a facecodes.json with multiple IDs
    all_facecodes_file = os.path.join(facecode_dir, "facecodes.json")
    print(f"Checking all face codes file: {all_facecodes_file}")
    
    if os.path.exists(all_facecodes_file):
        try:
            print(f"Found all face codes file")
            with open(all_facecodes_file, 'r') as f:
                all_data = json.load(f)
                if employee_id in all_data and 'face_embedding' in all_data[employee_id]:
                    print(f"Found face code for ID {employee_id} in all face codes file")
                    return all_data[employee_id]['face_embedding']
        except Exception as e:
            print(f"Error reading all face codes file: {str(e)}")
    
    # If we've reached here, we couldn't find face data for this ID
    print(f"Could not find face code for employee ID: {employee_id}")
    
    # As a last resort, create a blank file as a placeholder
    try:
        print(f"Creating empty placeholder file for ID {employee_id}")
        with open(facecode_file, 'w') as f:
            json.dump({"employee_id": employee_id, "face_embedding": None}, f)
    except Exception as e:
        print(f"Error creating placeholder file: {str(e)}")
    
    return None

def save_facecode_to_file(employee_id, facecode):
    """
    Save face embedding to a file (for testing purposes).
    In a real application, this would update the SQLite database.
    """
    # Create directory if it doesn't exist
    facecodes_dir = os.path.join(script_dir, "facecodes")
    Path(facecodes_dir).mkdir(parents=True, exist_ok=True)
    
    # Save to file
    facecode_file = os.path.join(facecodes_dir, f"{employee_id}.json")
    with open(facecode_file, 'w') as f:
        json.dump({'face_embedding': facecode}, f)
    
    return facecode_file

# Capture face and generate facecode
def capture_face_for_id(employee_id, output_image=None):
    """
    Capture face from webcam and generate facecode for the given employee ID.
    """
    # Check if models are available
    if not fr.check_models():
        return json.dumps({
            'success': False,
            'message': 'Missing required model files'
        })
    
    try:
        # Initialize models
        face_detector, shape_predictor, face_recognizer = fr.initialize_models()
        
        # Open webcam
        cap = cv2.VideoCapture(0)
        
        if not cap.isOpened():
            return json.dumps({
                'success': False,
                'message': 'Could not open webcam'
            })
        
        # Set up window
        cv2.namedWindow('Face Capture', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Face Capture', 640, 480)
        
        face_captured = False
        result_embedding = None
        captured_frame = None
        
        print("Press 'c' to capture face when ready, 'q' to quit")
        
        while not face_captured:
            # Capture frame
            ret, frame = cap.read()
            
            if not ret:
                break
            
            # Detect faces
            faces = fr.detect_faces(frame, face_detector)
            
            # Draw rectangles and display instructions
            display_frame = frame.copy()
            if faces:
                display_frame = fr.draw_faces(display_frame, faces)
                cv2.putText(display_frame, "Position your face in the green rectangle", 
                           (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                cv2.putText(display_frame, "Press 'c' to capture, 'q' to quit", 
                           (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
            else:
                cv2.putText(display_frame, "No face detected", 
                           (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
            
            # Display frame
            cv2.imshow('Face Capture', display_frame)
            
            # Handle key presses
            key = cv2.waitKey(1) & 0xFF
            if key == ord('q'):
                face_captured = True
                result_embedding = None
                break
            elif key == ord('c') and faces:
                # Capture face and generate embedding
                face = faces[0]
                embedding = fr.generate_face_embedding(frame, face, shape_predictor, face_recognizer)
                encoded_embedding = fr.encode_face_embedding(embedding)
                
                # Save embedding
                facecode_file = save_facecode_to_file(employee_id, encoded_embedding)
                
                # Save captured image if requested
                if output_image:
                    image_path = output_image
                else:
                    image_path = facecode_file.replace('.json', '.jpg')
                
                cv2.imwrite(image_path, frame)
                
                face_captured = True
                result_embedding = encoded_embedding
                captured_frame = frame
        
        # Release resources
        cap.release()
        cv2.destroyAllWindows()
        
        if result_embedding:
            # Encode captured frame as base64 for returning to Qt
            _, buffer = cv2.imencode('.jpg', captured_frame)
            jpg_as_text = base64.b64encode(buffer).decode('utf-8')
            
            return json.dumps({
                'success': True,
                'employee_id': employee_id,
                'facecode': result_embedding,
                'image': jpg_as_text
            })
        else:
            return json.dumps({
                'success': False,
                'message': 'No face captured'
            })
    
    except Exception as e:
        return json.dumps({
            'success': False,
            'message': f'Error: {str(e)}'
        })

# Verify face against stored facecode
def verify_face_for_id(image_path, employee_id):
    """
    Verify a face in an image against the stored facecode for the given employee ID.
    """
    # Check if image exists
    if not os.path.exists(image_path):
        return json.dumps({
            'success': False,
            'message': f'Image file not found: {image_path}'
        })
    
    # Get facecode from "database"
    stored_embedding = get_facecode_from_db(employee_id)
    
    if not stored_embedding:
        return json.dumps({
            'success': False,
            'message': f'No facial data found for employee ID: {employee_id}'
        })
    
    try:
        # Verify face
        match, result_image, message = fr.verify_face(image_path, stored_embedding)
        
        if result_image is not None:
            # Encode result image as base64 for returning to Qt
            _, buffer = cv2.imencode('.jpg', result_image)
            jpg_as_text = base64.b64encode(buffer).decode('utf-8')
            
            return json.dumps({
                'success': True,
                'match': match,
                'employee_id': employee_id,
                'image': jpg_as_text,
                'confidence': 1.0 if match else 0.0  # Simplified confidence value
            })
        else:
            return json.dumps({
                'success': False,
                'message': message
            })
    
    except Exception as e:
        return json.dumps({
            'success': False,
            'message': f'Error: {str(e)}'
        })

# Verify face from webcam
def verify_face_from_webcam(employee_id):
    """
    Capture a face from webcam and verify against the stored facecode.
    """
    # Check if models are available
    if not fr.check_models():
        return json.dumps({
            'success': False,
            'message': 'Missing required model files'
        })
    
    # Get facecode from "database"
    stored_embedding = get_facecode_from_db(employee_id)
    
    if not stored_embedding:
        return json.dumps({
            'success': False,
            'message': f'No facial data found for employee ID: {employee_id}'
        })
    
    try:
        # Initialize models
        face_detector, shape_predictor, face_recognizer = fr.initialize_models()
        
        # Open webcam
        cap = cv2.VideoCapture(0)
        
        if not cap.isOpened():
            return json.dumps({
                'success': False,
                'message': 'Could not open webcam'
            })
        
        # Set up window
        cv2.namedWindow('Face Verification', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Face Verification', 640, 480)
        
        verification_done = False
        verification_result = None
        result_image = None
        
        print("Press 'v' to verify face when ready, 'q' to quit")
        
        while not verification_done:
            # Capture frame
            ret, frame = cap.read()
            
            if not ret:
                break
            
            # Detect faces
            faces = fr.detect_faces(frame, face_detector)
            
            # Draw rectangles and display instructions
            display_frame = frame.copy()
            if faces:
                display_frame = fr.draw_faces(display_frame, faces)
                cv2.putText(display_frame, "Position your face in the green rectangle", 
                           (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                cv2.putText(display_frame, "Press 'v' to verify, 'q' to quit", 
                           (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
            else:
                cv2.putText(display_frame, "No face detected", 
                           (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
            
            # Display frame
            cv2.imshow('Face Verification', display_frame)
            
            # Handle key presses
            key = cv2.waitKey(1) & 0xFF
            if key == ord('q'):
                verification_done = True
                verification_result = False
                break
            elif key == ord('v') and faces:
                # Verify face
                face = faces[0]
                face_embedding = fr.generate_face_embedding(frame, face, shape_predictor, face_recognizer)
                
                # Decode stored embedding
                stored_face_embedding = fr.decode_face_embedding(stored_embedding)
                
                # Check if it's the same person
                match = fr.is_same_person(face_embedding, stored_face_embedding)
                
                # Draw rectangle around face (green if match, red if not)
                verify_frame = frame.copy()
                rect = face.rect
                x, y, x2, y2 = rect.left(), rect.top(), rect.right(), rect.bottom()
                color = (0, 255, 0) if match else (0, 0, 255)  # Green if match, red if not
                cv2.rectangle(verify_frame, (x, y), (x2, y2), color, 2)
                
                # Add text indicating match status
                text = "Match!" if match else "No Match"
                cv2.putText(verify_frame, text, (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, color, 2)
                
                # Display verification result for 2 seconds
                cv2.imshow('Face Verification', verify_frame)
                cv2.waitKey(2000)
                
                verification_done = True
                verification_result = match
                result_image = verify_frame
        
        # Release resources
        cap.release()
        cv2.destroyAllWindows()
        
        if verification_result is not None and result_image is not None:
            # Encode result image as base64 for returning to Qt
            _, buffer = cv2.imencode('.jpg', result_image)
            jpg_as_text = base64.b64encode(buffer).decode('utf-8')
            
            return json.dumps({
                'success': True,
                'match': verification_result,
                'employee_id': employee_id,
                'image': jpg_as_text
            })
        else:
            return json.dumps({
                'success': False,
                'message': 'Verification canceled or failed'
            })
    
    except Exception as e:
        return json.dumps({
            'success': False,
            'message': f'Error: {str(e)}'
        })

# Detect faces in an image and return the results
def detect_face_in_image(image_path, draw_rectangle=True):
    """
    Detect faces in an image and return the face embedding.
    Args:
        image_path: Path to the image file
        draw_rectangle: Whether to draw a green rectangle around detected faces
    """
    # Check if image exists
    if not os.path.exists(image_path):
        print(f"Error: Image file not found: {image_path}")
        return json.dumps({
            'success': False,
            'message': f'Image file not found: {image_path}'
        })
    
    try:
        print(f"Loading image from: {image_path}")
        # Check if models are available
        if not fr.check_models():
            print("Error: Required model files are missing")
            return json.dumps({
                'success': False,
                'message': 'Missing required model files'
            })
        
        print("Initializing models...")
        # Initialize models
        face_detector, shape_predictor, face_recognizer = fr.initialize_models()
        
        print("Loading image...")
        # Load image
        image = cv2.imread(image_path)
        if image is None:
            print(f"Error: Failed to load image: {image_path}")
            return json.dumps({
                'success': False,
                'message': f'Failed to load image: {image_path}'
            })
        
        print(f"Image loaded successfully. Shape: {image.shape}")
        print("Detecting faces...")
        # Detect faces
        faces = fr.detect_faces(image, face_detector)
        
        print(f"Found {len(faces)} faces")
        # Check if faces were detected
        if not faces:
            print("No faces detected in the image")
            return json.dumps({
                'success': True,
                'has_faces': False,
                'message': 'No faces detected in the image'
            })
        
        # Use the first detected face
        face = faces[0]
        print("Generating face embedding...")
        
        # Generate face embedding
        face_embedding = fr.generate_face_embedding(image, face, shape_predictor, face_recognizer)
        encoded_embedding = fr.encode_face_embedding(face_embedding)
        
        print("Creating result image...")
        # Create image with face rectangle
        result_image = image.copy()
        
        # Draw rectangle around face
        if hasattr(face, 'rect'):  # CNN detector
            rect = face.rect
        else:  # HOG detector
            rect = face
            
        x, y, x2, y2 = rect.left(), rect.top(), rect.right(), rect.bottom()
        
        if draw_rectangle:
            # Create a thicker, more visible rectangle (4px thickness)
            cv2.rectangle(result_image, (x, y), (x2, y2), (0, 255, 0), 4)  # Thicker green rectangle
            
            # Add text indicating face was detected
            font_scale = min(result_image.shape[1] / 1000.0, 1.0) * 1.2  # Scale font based on image size
            cv2.putText(result_image, "Face Detected", (x, max(y-10, 20)), cv2.FONT_HERSHEY_SIMPLEX, 
                       font_scale, (0, 255, 0), 2)
        
        print("Converting result image to base64...")
        # Convert result image to base64 for returning to Qt
        _, buffer = cv2.imencode('.jpg', result_image)
        jpg_as_text = base64.b64encode(buffer).decode('utf-8')
        
        print("Face detection completed successfully")
        return json.dumps({
            'success': True,
            'has_faces': True,
            'face_embedding': encoded_embedding,
            'message': 'Face detected successfully',
            'image': jpg_as_text
        })
    
    except Exception as e:
        print(f"Error in detect_face_in_image: {str(e)}")
        import traceback
        traceback.print_exc()
        return json.dumps({
            'success': False,
            'message': f'Error: {str(e)}'
        })

# Main function
if __name__ == "__main__":
    try:
        print("Python version:", sys.version)
        print("Current directory:", os.getcwd())
        print("Script location:", os.path.abspath(__file__))
        
        # Check if running with admin privileges
        import ctypes
        is_admin = False
        try:
            is_admin = ctypes.windll.shell32.IsUserAnAdmin() != 0
        except:
            # Not on Windows or other error
            pass
        print(f"Running with admin privileges: {is_admin}")
        
        # Parse command line arguments
        parser = argparse.ArgumentParser(description='Face recognition bridge for BioVec')
        parser.add_argument('--capture-facecode', action='store_true', help='Capture a face and generate facecode')
        parser.add_argument('--verify-face', action='store_true', help='Verify a face against stored facecode')
        parser.add_argument('--verify-webcam', action='store_true', help='Verify face from webcam against stored facecode')
        parser.add_argument('--detect-face', action='store_true', help='Detect face in an image and return embedding')
        parser.add_argument('--id', type=str, help='Employee ID')
        parser.add_argument('--image', type=str, help='Path to an image file')
        parser.add_argument('--draw-rectangle', action='store_true', help='Draw rectangle around detected face')
        args = parser.parse_args()
        
        # Set OpenCV DNN backend to CPU mode if not using CUDA
        cv2.setUseOptimized(True)
        
        # Perform requested action
        if args.capture_facecode:
            if not args.id:
                print(json.dumps({'success': False, 'message': 'Employee ID is required'}))
                sys.exit(1)
                
            print(capture_face_for_id(args.id))
            
        elif args.verify_face:
            if not args.id:
                print(json.dumps({'success': False, 'message': 'Employee ID is required'}))
                sys.exit(1)
                
            if not args.image:
                print(json.dumps({'success': False, 'message': 'Image path is required'}))
                sys.exit(1)
                
            print(verify_face_for_id(args.image, args.id))
            
        elif args.verify_webcam:
            if not args.id:
                print(json.dumps({'success': False, 'message': 'Employee ID is required'}))
                sys.exit(1)
                
            print(verify_face_from_webcam(args.id))
            
        elif args.detect_face:
            if not args.image:
                print(json.dumps({'success': False, 'message': 'Image path is required'}))
                sys.exit(1)
                
            print(detect_face_in_image(args.image, args.draw_rectangle))
            
        else:
            print(json.dumps({'success': False, 'message': 'No valid action specified'}))
            parser.print_help()
            sys.exit(1)
    except Exception as e:
        import traceback
        print(f"Unhandled exception in face_recognition_bridge.py: {str(e)}", file=sys.stderr)
        traceback.print_exc(file=sys.stderr)
        print(json.dumps({'success': False, 'message': f"Unhandled exception: {str(e)}"}))
        sys.exit(1) 