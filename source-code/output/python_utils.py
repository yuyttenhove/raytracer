import cv2
import numpy as np

def txt_to_image(filename, savename):
    data = np.loadtxt(filename)
    cv2.imwrite(savename, data*255)

if __name__ == "__main__":
    fname = "result.txt"
    txt_to_image(fname, "result.jpg")
