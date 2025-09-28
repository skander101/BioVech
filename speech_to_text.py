#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys
import json
import time
import argparse
from pathlib import Path
import pyaudio
import wave
from vosk import Model, KaldiRecognizer

def list_microphones():
    """List all available microphones with their indices"""
    try:
        # Debug environment information
        print("Python version:", sys.version, file=sys.stderr)
        print("Current directory:", os.getcwd(), file=sys.stderr)
        print("Script location:", os.path.abspath(__file__), file=sys.stderr)
        
        # Check if running with admin privileges
        try:
            admin = False
            if os.name == 'nt':  # Windows
                import ctypes
                admin = ctypes.windll.shell32.IsUserAnAdmin() != 0
            else:  # Unix/Linux/Mac
                admin = os.geteuid() == 0  # 0 is root
            print(f"Running with admin privileges: {admin}", file=sys.stderr)
        except Exception as e:
            print(f"Error checking admin privileges: {e}", file=sys.stderr)
        
        try:
            import pyaudio
            print("PyAudio version:", pyaudio.__version__, file=sys.stderr)
        except ImportError:
            print("ERROR: PyAudio module not found! Please install with 'pip install pyaudio'", file=sys.stderr)
            # Very explicit output for Qt
            print("QT_JSON_START")
            print("[]")
            print("QT_JSON_END")
            
            print("--- MICROPHONES BEGIN ---")
            print("--- MICROPHONES END ---")
            sys.stdout.flush()
            return []
        except Exception as e:
            print(f"ERROR loading PyAudio module: {e}", file=sys.stderr)
            print("QT_JSON_START")
            print("[]")
            print("QT_JSON_END")
            
            print("--- MICROPHONES BEGIN ---")
            print("--- MICROPHONES END ---")
            sys.stdout.flush()
            return []
        
        # Try with additional error handling
        try:
            p = pyaudio.PyAudio()
        except Exception as e:
            print(f"ERROR creating PyAudio instance: {e}", file=sys.stderr)
            print("This may be due to permission issues accessing audio devices", file=sys.stderr)
            print("Try running the program as administrator", file=sys.stderr)
            
            print("QT_JSON_START")
            print("[]")
            print("QT_JSON_END")
            
            print("--- MICROPHONES BEGIN ---")
            print("--- MICROPHONES END ---")
            sys.stdout.flush()
            return []
            
        info = []
        
        try:
            device_count = p.get_device_count()
            print("Scanning for microphones...", file=sys.stderr)
            print(f"Device count: {device_count}", file=sys.stderr)
            
            if device_count == 0:
                print("WARNING: No audio devices detected! This could be a permissions issue.", file=sys.stderr)
                print("Try running as administrator.", file=sys.stderr)
        except Exception as e:
            print(f"ERROR getting device count: {e}", file=sys.stderr)
            print("This may be due to permission issues accessing audio devices", file=sys.stderr)
            device_count = 0
        
        # Get default input device and host API info
        try:
            default_input = p.get_default_input_device_info()
            print(f"Default input device: {default_input['index']} - {default_input['name']}", file=sys.stderr)
        except Exception as e:
            print(f"No default input device found: {e}", file=sys.stderr)
        
        # List all available host APIs
        print("\nHost APIs:", file=sys.stderr)
        try:
            for i in range(p.get_host_api_count()):
                try:
                    api_info = p.get_host_api_info_by_index(i)
                    print(f"  {i}: {api_info['name']}", file=sys.stderr)
                except Exception as e:
                    print(f"  Error getting host API {i}: {e}", file=sys.stderr)
        except Exception as e:
            print(f"Error listing host APIs: {e}", file=sys.stderr)
        
        print("\nAll audio devices (including output devices):", file=sys.stderr)
        for i in range(device_count):
            try:
                device_info = p.get_device_info_by_index(i)
                is_input = device_info.get('maxInputChannels') > 0
                is_output = device_info.get('maxOutputChannels') > 0
                print(f"  {i}: {device_info['name']} (Input: {is_input}, Output: {is_output})", file=sys.stderr)
                
                # Only include input devices (microphones)
                if is_input:
                    # Get a simple ASCII-safe name
                    device_name = str(device_info.get('name', '')).strip()
                    
                    # Truncate excessively long names
                    if len(device_name) > 50:
                        device_name = device_name[:47] + "..."
                    
                    # ASCII-only name for compatibility
                    safe_name = ''.join(c if ord(c) < 128 else '_' for c in device_name)
                    
                    mic_data = {
                        'index': i,
                        'name': safe_name,
                        'channels': int(device_info.get('maxInputChannels')),
                        'sample_rate': int(device_info.get('defaultSampleRate'))
                    }
                    info.append(mic_data)
                    print(f"Found microphone: {i} - {safe_name}", file=sys.stderr)
            except Exception as e:
                print(f"Error getting device info for index {i}: {str(e)}", file=sys.stderr)
        
        try:
            p.terminate()
        except Exception as e:
            print(f"Error terminating PyAudio: {e}", file=sys.stderr)
        
        if not info:
            print("No microphones found! Check your system settings and permissions.", file=sys.stderr)
            # We still need to output the empty formats for Qt to parse
            print("QT_JSON_START")
            print("[]")
            print("QT_JSON_END")
            
            print("--- MICROPHONES BEGIN ---")
            print("--- MICROPHONES END ---")
            sys.stdout.flush()
        else:
            print(f"Found {len(info)} microphone(s)", file=sys.stderr)
            
            # Make a very simple string representation for Qt
            json_result = json.dumps(info)
            print("JSON output:", json_result, file=sys.stderr)  # Debug output
            
            # Print multiple formats for Qt to try parsing
            print("QT_JSON_START")
            print(json_result)
            print("QT_JSON_END")
            
            # Also print a simple format directly for Qt
            print("--- MICROPHONES BEGIN ---")
            for mic in info:
                print(f"{mic['index']}:{mic['name']}")
            print("--- MICROPHONES END ---")
            
            sys.stdout.flush()
        
        return info
    except ImportError:
        print("Error: PyAudio not installed. Please install with 'pip install pyaudio'", file=sys.stderr)
        print("QT_JSON_START")
        print("[]")
        print("QT_JSON_END")
        
        print("--- MICROPHONES BEGIN ---")
        print("--- MICROPHONES END ---")
        sys.stdout.flush()
        return []
    except Exception as e:
        print(f"Error listing microphones: {str(e)}", file=sys.stderr)
        print(f"Error type: {type(e).__name__}", file=sys.stderr)
        print(f"Error details: {repr(e)}", file=sys.stderr)
        import traceback
        traceback.print_exc(file=sys.stderr)
        print("QT_JSON_START")
        print("[]")
        print("QT_JSON_END")
        
        print("--- MICROPHONES BEGIN ---")
        print("--- MICROPHONES END ---")
        sys.stdout.flush()
        return []

def record_audio(device_index, duration=5):
    CHUNK = 1024
    FORMAT = pyaudio.paInt16
    CHANNELS = 1
    RATE = 16000
    
    p = pyaudio.PyAudio()
    
    stream = p.open(format=FORMAT,
                   channels=CHANNELS,
                   rate=RATE,
                   input=True,
                   input_device_index=device_index,
                   frames_per_buffer=CHUNK)
    
    #print("Recording...")
    frames = []
    
    for i in range(0, int(RATE / CHUNK * duration)):
        data = stream.read(CHUNK)
        frames.append(data)
    
    #print("Done recording")
    
    stream.stop_stream()
    stream.close()
    p.terminate()
    return frames

def save_audio(frames, filename="temp.wav"):
    CHUNK = 1024
    FORMAT = pyaudio.paInt16
    CHANNELS = 1
    RATE = 16000
    
    wf = wave.open(filename, 'wb')
    wf.setnchannels(CHANNELS)
    wf.setsampwidth(pyaudio.get_sample_size(FORMAT))
    wf.setframerate(RATE)
    wf.writeframes(b''.join(frames))
    wf.close()

def recognize_speech(audio_file):
    # Define the model path - adjust this to your actual path
    model_path = "C:/Users/Dell/OneDrive/Desktop/Atelier_Connexion/Atelier_Connexion/2a14-bytebuilder/vosk-model-small-fr-0.22"

    # Verify the model exists
    if not os.path.exists(model_path):
        print(f"Error: Vosk model not found at {model_path}")
        print("Please download the French model from https://alphacephei.com/vosk/models")
        return ""

    try:
        # Load the model with better error handling
        #print(f"Loading model from {model_path}...")
        model = Model(model_path)
        #print("Model loaded successfully") //Kont tchouf fel credentials nigga

        wf = wave.open(audio_file, "rb")
        rec = KaldiRecognizer(model, wf.getframerate())
        rec.SetWords(True)

        while True:
            data = wf.readframes(4000)
            if len(data) == 0:
                break
            if rec.AcceptWaveform(data):
                result = json.loads(rec.Result())
                if result.get("text", "").strip():
                    print(result["text"])
                    return result["text"]

        result = json.loads(rec.FinalResult())
        if result.get("text", "").strip():
            print(result["text"])
            return result["text"]

        return ""

    except Exception as e:
        print(f"Error in speech recognition: {str(e)}")
        return ""
def main():
    if len(sys.argv) > 1 and sys.argv[1] == "--list-mics":
        list_microphones()
        return
        
    if len(sys.argv) < 3:
        print("Usage: python speech_to_text.py --device <device_index> [--timeout <seconds>]")
        return
        
    device_index = int(sys.argv[2])
    timeout = 5
    if len(sys.argv) > 3 and sys.argv[3] == "--timeout":
        timeout = int(sys.argv[4])
    
    try:
        frames = record_audio(device_index, timeout)
        save_audio(frames)
        text = recognize_speech("temp.wav")
        if text:
            print(text)
        else:
            print("No speech detected")
    except Exception as e:
        print(f"Error: {str(e)}")
    finally:
        if os.path.exists("temp.wav"):
            os.remove("temp.wav")

if __name__ == "__main__":
    main()
