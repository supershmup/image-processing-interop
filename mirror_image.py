import cv2
import numpy as np
import os
print(os.getcwd())

def mirror_image(image):
    # Assuming the image is passed as a numpy array
    mirrored_image = cv2.flip(image, 1)  # Flip around the y-axis
    return mirrored_image
