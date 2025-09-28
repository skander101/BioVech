import sys
import os
import numpy as np
import cv2
import tensorflow as tf
from deepface import DeepFace

def check_dependencies():
    """Check and print versions of key dependencies"""
    try:
        import keras
        print(f"TensorFlow version: {tf.__version__}")
        print(f"Keras version: {keras.__version__}")
        print(f"OpenCV version: {cv2.__version__}")
        print(f"NumPy version: {np.__version__}")
        print("DeepFace is installed")
        print("\nAll required packages are installed.\n")
        return True
    except Exception as e:
        print(f"Error checking dependencies: {str(e)}")
        return False

def generate_face_embedding(image_path):
    """Generates a unique face embedding code from an image"""
    
    try:
        print(f"Processing image: {image_path}")
        
        # Verify the image exists and can be opened
        if not os.path.exists(image_path):
            raise FileNotFoundError(f"Image file not found: {image_path}")
            
        img = cv2.imread(image_path)
        if img is None:
            raise ValueError(f"Failed to load image: {image_path}")
        
        print("Detecting and analyzing face...")
        try:
            # Get face embedding using DeepFace
            embedding_objs = DeepFace.represent(
                img_path=image_path,
                model_name="VGG-Face",
                detector_backend="opencv",
                enforce_detection=True,
                align=True
            )
            
            if not embedding_objs:
                print("No face detected in the image")
                return None
                
            # Get the embedding vector from the first detected face
            embedding = embedding_objs[0]["embedding"]
            
            # Normalize the embedding vector
            normalized_embedding = embedding / np.linalg.norm(embedding)
            
            # Convert to a compact hexadecimal representation
            compact_embedding = ""
            for i in range(min(128, len(normalized_embedding))):
                val = int((normalized_embedding[i] + 1) * 127.5)
                compact_embedding += f"{val:02x}"
            
            print(f"\nFace Embedding Unique ID:\n{compact_embedding}")
            
            # Show sample of embedding vector
            print(f"\nRaw Embedding Vector (first 10 values):")
            for i in range(min(10, len(embedding))):
                print(f"{embedding[i]:.6f}")
            
            print(f"\nTotal vector length: {len(embedding)} dimensions")
            return compact_embedding
            
        except ValueError as e:
            if "No face detected" in str(e):
                print("No face was detected in the image. Please try with a clearer face photo.")
            else:
                print(f"Error during face analysis: {str(e)}")
            return None
            
    except Exception as e:
        print(f"\nERROR: {str(e)}")
        print("\nStacktrace:")
        import traceback
        traceback.print_exc()
        return None

if __name__ == "__main__":
    print("\nChecking dependencies...")
    if not check_dependencies():
        sys.exit(1)
        
    if len(sys.argv) < 2:
        print("\nUsage: python face_embedding_processor.py <image_path>")
        sys.exit(1)
    
    image_path = sys.argv[1]
    result = generate_face_embedding(image_path)
    
    if result is None:
        sys.exit(1)
