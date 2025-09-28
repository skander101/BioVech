import numpy as np
print("NumPy Available:", np.__version__)

# Test array operations
a = np.array([1.0, 2.0, 3.0])
b = np.array([4.0, 5.0, 6.0])
distance = np.linalg.norm(a - b)
print("Distance test:", distance) 