# ByteBuilder Voice Recognition System

This application includes a voice recognition system that allows users to input text using speech. The system uses Python with the Vosk library for offline speech recognition.

## Setup Instructions

### Requirements
- Qt application (already built)
- Python 3.6 or newer
- PyAudio
- Vosk

### Installation Steps

1. Ensure Python is installed on your system (version 3.6 or higher)

2. Install the required Python packages:
   ```bash
   pip install vosk pyaudio
   ```

3. Download the French Vosk model:
   - Visit https://alphacephei.com/vosk/models
   - Download the small French model (vosk-model-small-fr-0.22)
   - Extract the model folder to the same directory as the application executable

### Folder Structure
Your folder structure should look like this:
```
application_directory/
│
├── YourApp.exe (or executable)
├── speech_to_text.py
├── vosk-model-small-fr-0.22/
│   ├── (model files)
│   └── ...
└── (other application files)
```

## Using Voice Recognition

1. Start the application
2. Go to the login screen
3. Under "Voice Recognition Settings":
   - Click "Refresh" to scan for available microphones
   - Select your preferred microphone from the dropdown
   - Adjust the volume slider if needed
4. Click "Start Listening" to begin voice recognition
5. Speak clearly for up to 10 seconds
6. The recognized text will appear in the text display field
7. If "Auto-fill username" is checked, the recognized text will automatically be entered in the username field

## Troubleshooting

### No Microphones Found
- Ensure your microphone is properly connected
- Check if your microphone is enabled in your system settings
- Try unplugging and reconnecting your microphone

### Python Not Found
- Ensure Python is installed and in your system PATH
- Try installing Python from the official website (https://python.org)

### Model Not Found
- Verify that the vosk-model-small-fr-0.22 folder is in the same directory as the application
- Check that the model folder name is exactly "vosk-model-small-fr-0.22"

### Recognition Quality Issues
- Speak clearly and at a moderate pace
- Reduce background noise
- Position the microphone closer to your mouth
- Try adjusting the volume slider

## Credits
- Voice recognition powered by [Vosk](https://alphacephei.com/vosk/)
- Speech processing by [PyAudio](https://people.csail.mit.edu/hubert/pyaudio/) 
