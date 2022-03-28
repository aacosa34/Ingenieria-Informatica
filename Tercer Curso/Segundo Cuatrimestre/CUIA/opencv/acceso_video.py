import cv2
import numpy as np

video = cv2.VideoCapture("escenario.mp4")
fps = video.get(cv2.CAP_PROP_FPS)

if not video.isOpened():
    print("No se puede abrir el fichero")
    exit()
while True:
    ret, frame = video.read()

    if not ret:
        print("No he podido leer el frame")
        break

    cv2.imshow('VIDEO', frame)

    if cv2.waitKey(1) == ord(' '):
        break

video.release()
cv2.destroyWindow('VIDEO')