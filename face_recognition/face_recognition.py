#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Face recognition module for the BioVec system.

This module provides facial recognition functionality:
- Face detection
- Face landmark detection
- Face recognition/embedding generation
- Face similarity comparison
"""

import os
import sys
import json
import base64
import tempfile
from pathlib import Path
import dlib
import cv2
import numpy as np

# Get the current directory for model loading
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
MODELS_DIR = os.path.join(SCRIPT_DIR, "models")

# Model file paths
SHAPE_PREDICTOR_PATH = os.path.join(MODELS_DIR, "shape_predictor_68_face_landmarks.dat")
FACE_RECOGNITION_MODEL_PATH = os.path.join(MODELS_DIR, "dlib_face_recognition_resnet_model_v1.dat")
FACE_DETECTOR_PATH = os.path.join(MODELS_DIR, "mmod_human_face_detector.dat")

# Fallback paths for compatibility with older versions
if not os.path.exists(FACE_DETECTOR_PATH):
    print(f"Warning: Could not find face detector at {FACE_DETECTOR_PATH}")
    FACE_DETECTOR_PATH = None

# Debug function to check model availability
def check_models():
    """Check if required model files are available"""
    print(f"Checking model files in directory: {MODELS_DIR}")
    if not os.path.isdir(MODELS_DIR):
        print(f"Error: Models directory does not exist: {MODELS_DIR}")
        return False
    
    # Check for shape predictor
    if not os.path.exists(SHAPE_PREDICTOR_PATH):
        print(f"Error: Shape predictor model not found: {SHAPE_PREDICTOR_PATH}")
        return False
        
    # Check for face recognition model
    if not os.path.exists(FACE_RECOGNITION_MODEL_PATH):
        print(f"Error: Face recognition model not found: {FACE_RECOGNITION_MODEL_PATH}")
        return False
    
    # Log model file sizes to check for corruption
    try:
        shape_predictor_size = os.path.getsize(SHAPE_PREDICTOR_PATH)
        face_recog_size = os.path.getsize(FACE_RECOGNITION_MODEL_PATH)
        print(f"Shape predictor size: {shape_predictor_size / (1024*1024):.2f} MB")
        print(f"Face recognition model size: {face_recog_size / (1024*1024):.2f} MB")
        
        # Check for unreasonably small files which might indicate corruption
        if shape_predictor_size < 50000000:  # ~50MB expected size
            print(f"Warning: Shape predictor model appears too small: {shape_predictor_size} bytes")
            return False
            
        if face_recog_size < 18000000:  # ~18MB expected size
            print(f"Warning: Face recognition model appears too small: {face_recog_size} bytes")
            return False
    except Exception as e:
        print(f"Error checking model file sizes: {str(e)}")
        return False
    
    print("All model files are available and have reasonable sizes")
    return True

def initialize_models():
    """Initialize face detection, landmark detection and recognition models"""
    try:
        # Always use HOG-based detector for reliability
        face_detector = dlib.get_frontal_face_detector()
        
        # Create shape predictor
        shape_predictor = dlib.shape_predictor(SHAPE_PREDICTOR_PATH)
        
        # Create face recognition model
        face_recognizer = dlib.face_recognition_model_v1(FACE_RECOGNITION_MODEL_PATH)
        
        # Return models
        return face_detector, shape_predictor, face_recognizer
    except Exception as e:
        print(f"Error initializing models: {str(e)}")
        import traceback
        traceback.print_exc()
        raise

def detect_faces(image, detector):
    """Detect faces in an image using the provided detector"""
    try:
        # Add some input validation
        if image is None:
            print("Error: Input image is None")
            return []
            
        # Make sure the image is of reasonable size (limit to 1280px on largest dimension)
        h, w = image.shape[:2]
        max_dimension = 1280
        if max(h, w) > max_dimension:
            scale = max_dimension / max(h, w)
            new_width = int(w * scale)
            new_height = int(h * scale)
            print(f"Resizing image from {w}x{h} to {new_width}x{new_height} to save memory")
            image = cv2.resize(image, (new_width, new_height))
        
        # Don't upsample the image (0 instead of 1) to use less memory
        print("Detecting faces with HOG detector")
        return detector(image, 0)  # No upsampling to save memory
    except Exception as e:
        print(f"Error detecting faces: {str(e)}")
        import traceback
        traceback.print_exc()
        return []

def generate_face_embedding(image, face, shape_predictor, face_recognizer):
    """Generate a face embedding from an image and face location"""
    try:
        # Get face landmark points
        if hasattr(face, 'rect'):  # CNN detector
            landmarks = shape_predictor(image, face.rect)
        else:  # HOG detector
            landmarks = shape_predictor(image, face)
            
        # Get face embedding
        face_embedding = face_recognizer.compute_face_descriptor(image, landmarks)
        
        return face_embedding
    except Exception as e:
        print(f"Error generating face embedding: {str(e)}")
        raise

def encode_face_embedding(face_embedding):
    """Encode face embedding to a string format for storage"""
    if face_embedding is None:
        return None
    
    # Convert dlib's vector to a Python list
    embedding_list = list(face_embedding)
    
    # Format to a specific precision and join with commas
    return ','.join([f"{value:.8f}" for value in embedding_list])

def decode_face_embedding(embedding_string):
    """Decode a face embedding string back to a vector"""
    if not embedding_string:
        return None
    
    # Split the string and convert back to floating point numbers
    try:
        embedding_list = [float(value) for value in embedding_string.split(',')]
        return np.array(embedding_list)
    except Exception as e:
        print(f"Error decoding face embedding: {str(e)}")
        return None

def is_same_person(embedding1, embedding2, threshold=0.6):
    """Compare two face embeddings to determine if they're the same person"""
    if embedding1 is None or embedding2 is None:
        return False
    
    # Convert to numpy arrays if they're not already
    if not isinstance(embedding1, np.ndarray):
        embedding1 = np.array(embedding1)
    if not isinstance(embedding2, np.ndarray):
        embedding2 = np.array(embedding2)
    
    # Calculate Euclidean distance
    distance = np.linalg.norm(embedding1 - embedding2)
    
    # Return True if distance is below threshold (smaller distance = more similar)
    return distance < threshold

def draw_face_landmarks(image, landmarks, color=(0, 255, 0), size=1):
    """Draw facial landmarks on an image"""
    for i in range(68):
        point = landmarks.part(i)
        cv2.circle(image, (point.x, point.y), size, color, -1)
    return image

def verify_face(image_path, stored_embedding):
    """Verify a face in an image against a stored embedding"""
    try:
        # Load image
        image = cv2.imread(image_path)
        if image is None:
            return False, None, f"Failed to load image: {image_path}"
        
        # Initialize models
        face_detector, shape_predictor, face_recognizer = initialize_models()
        
        # Detect faces
        faces = detect_faces(image, face_detector)
        
        if not faces:
            return False, None, "No faces detected in the image"
        
        # Use the first detected face
        face = faces[0]
        
        # Generate face embedding
        face_embedding = generate_face_embedding(image, face, shape_predictor, face_recognizer)
        
        # Decode stored embedding
        stored_face_embedding = decode_face_embedding(stored_embedding)
        
        # Compare embeddings
        match = is_same_person(face_embedding, stored_face_embedding)
        
        # Create result image with face rectangle
        result_image = image.copy()
        
        # Draw rectangle around face (green if match, red if not)
        if hasattr(face, 'rect'):  # CNN detector
            rect = face.rect
        else:  # HOG detector
            rect = face
            
        x, y, x2, y2 = rect.left(), rect.top(), rect.right(), rect.bottom()
        color = (0, 255, 0) if match else (0, 0, 255)  # Green if match, red if not
        cv2.rectangle(result_image, (x, y), (x2, y2), color, 2)
        
        # Add text indicating match status
        text = "Match!" if match else "No Match"
        cv2.putText(result_image, text, (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, color, 2)
        
        return match, result_image, "Face verification completed"
    
    except Exception as e:
        print(f"Error verifying face: {str(e)}")
        import traceback
        traceback.print_exc()
        return False, None, f"Error: {str(e)}"

# Main function for testing
if __name__ == "__main__":
    print("Face Recognition Module")
    print(f"Script directory: {SCRIPT_DIR}")
    print(f"Models directory: {MODELS_DIR}")
    
    # Check models
    print("\nChecking model files:")
    models_ok = check_models()
    print(f"Model check result: {'OK' if models_ok else 'FAILED'}")
    
    if not models_ok:
        print("\nModel files are missing or invalid.")
        print("Please run the install_dependencies.bat script to download them.")
        sys.exit(1)
    
    print("\nAll required model files are available.")
    print("The face recognition module is ready to use.") 