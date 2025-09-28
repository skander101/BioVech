# Facial Recognition System Setup Guide

This guide will help you set up and use the facial recognition system in your application.

## Prerequisites

Before you begin, make sure you have the following installed:

1. **Python 3.8 or later** - Download from [python.org](https://www.python.org/downloads/)
2. **Qt 6.x** - Your application should already be using this
3. **A working webcam** - For capturing and verifying faces

## Installation Steps

1. **Install Python Dependencies**

   Run the included `install_dependencies.bat` script to install all required packages and models:

   ```
   cd face_recognition
   ./install_dependencies.bat
   ```

   This will install the following:
   - OpenCV - For image processing and camera access
   - dlib - For face detection and recognition
   - numpy - For numerical operations
   
   It will also download the pre-trained models needed for facial recognition.

2. **Verify Installation**

   You can test that everything is working correctly by running:

   ```
   python face_recognition/face_recognition_bridge.py --capture-facecode --id test123
   ```

   This should open a camera window allowing you to capture a test face.

## How the System Works

The facial recognition system has two main components:

1. **Face Embedding Generation** ("facecode")
   - When a user registers their face, their facial features are converted to a 128-dimensional vector
   - This vector (or "facecode") uniquely identifies their face
   - The facecode is stored in the database for future verification

2. **Face Verification**
   - When a user attempts to log in, their current face is compared to the stored facecode
   - The system calculates the similarity between the faces
   - If the similarity is above a threshold, the verification succeeds

## Using the System

### Registering a Face

1. Log in with your ID and password
2. When prompted, choose to register your face
3. Position your face in the green rectangle
4. Press 'c' to capture your face
5. The system will generate your facecode and store it in the database

### Verifying Your Face

1. Enter your ID and password
2. When prompted, choose to verify your face
3. Position your face in the green rectangle
4. Press 'v' to verify your face
5. The system will compare your face to the stored facecode
6. If they match, you'll be logged in

## Troubleshooting

### System Requirements
- The facial recognition system requires a modern CPU
- A dedicated GPU is NOT required but can improve performance
- At least 2GB of free RAM is recommended

### Common Issues

1. **"Missing model files" error**
   - Run the `install_dependencies.bat` script again
   - Check that you have internet access to download the models

2. **"Could not open webcam" error**
   - Make sure your webcam is connected and working
   - Check if other applications are using the webcam
   - Try closing other applications that might be using the camera

3. **Face not detected**
   - Make sure you have good lighting conditions
   - Position your face to be fully visible in the frame
   - Try adjusting your distance from the camera

4. **Poor recognition accuracy**
   - Re-register your face under better lighting conditions
   - Ensure your face is well-lit and clearly visible during verification
   - Try to maintain a similar pose and expression as when you registered

## Security Considerations

The facial recognition system enhances security but is not foolproof. For critical operations, combine facial recognition with other authentication methods.

The system stores facial embeddings (mathematical representations) rather than actual images, enhancing privacy and security.

## Additional Resources

- [dlib Machine Learning Library](http://dlib.net/)
- [OpenCV Documentation](https://docs.opencv.org/)
- [Face Recognition Best Practices](https://www.nist.gov/programs-projects/face-recognition-vendor-test-frvt) 