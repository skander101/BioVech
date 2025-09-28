import numpy as np
import sys

def load_embedding(filename):
    try:
        with open(filename, 'r') as f:
            text = f.read().strip()
            values = [float(x) for x in text.split(',')]
            return np.array(values)
    except Exception as e:
        print(f"Error loading embedding from {filename}: {str(e)}", file=sys.stderr)
        return None

def compare_embeddings(file1, file2):
    embedding1 = load_embedding(file1)
    embedding2 = load_embedding(file2)
    
    if embedding1 is None or embedding2 is None:
        print("Failed to load one of the embeddings", file=sys.stderr)
        return 999.0
    
    try:
        # Calculate the Euclidean distance between embeddings
        distance = np.linalg.norm(embedding1 - embedding2)
        
        # Print debug info
        print(f"Distance: {distance}")
        print(f"Embedding1 length: {len(embedding1)}, Embedding2 length: {len(embedding2)}")
        
        # Debug first 5 values
        for i in range(min(5, len(embedding1), len(embedding2))):
            print(f"Value {i}: {embedding1[i]:.6f} vs {embedding2[i]:.6f}, diff: {abs(embedding1[i] - embedding2[i]):.6f}")
        
        # Return the distance as the final value
        return distance
    except Exception as e:
        print(f"Error calculating distance: {str(e)}", file=sys.stderr)
        return 999.0

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <embedding1_file> <embedding2_file>", file=sys.stderr)
        print(999.0)
        sys.exit(1)
    
    distance = compare_embeddings(sys.argv[1], sys.argv[2])
    print(distance)  # This is the final line that will be parsed for the distance value 