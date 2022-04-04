import cv2
import numpy as np
from matplotlib import pyplot as plt

cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("No se puede abrir la camara")
    exit()

histograma, (ax1, ax2, ax2) = plt.subplots(1, 3)
plt.ion()
plt.show()

while True:
    ret, frame = cap.read()
    if not ret:
        print("No he podido leer el frame")
        break

    framehsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    histoh = cv2.calcHist([framehsv], [0], None, [180], [0, 180])
    histos = cv2.calcHist([framehsv], [1], None, [256], [0, 256])
    histov = cv2.calcHist([framehsv], [2], None, [256], [0, 256])

    cv2.imshow('WEBCAM', frame)
    if cv2.waitKey(1) == ord(' '):
        break

    ax1.clear()
    ax1.set_title("TONO")
    ax1.plot(histoh)

    ax2.clear()
    ax2.set_title("SATURACION")
    ax2.plot(histos)

    ax3.clear()
    ax3.set_title("VALOR")
    ax3.plot(histov)

    histograma.canvas.flush_events()

cap.release()
cv2.destroyWindow('WEBCAM')
