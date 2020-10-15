import cv2
import numpy as np
from pathlib import Path

def txt_to_image(filename, savename):
    data = np.loadtxt(filename)
    cv2.imwrite(str(savename), data * 255)
    cv2.imshow("nice picture", data)
    cv2.waitKey(0)

if __name__ == "__main__":
    path = Path(__file__).parent
    fname = path / "result.txt"
    txt_to_image(fname, path / "result.jpg")

