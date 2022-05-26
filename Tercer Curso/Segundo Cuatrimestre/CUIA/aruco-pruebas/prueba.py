import cv2
import cv2.aruco as aruco
import numpy as np
import os

# Le pasamos la imagen, el tamanio del marcador, la cantidad de marcadores disponibles
# y una variable booleana que nos indica si pintar todos o no
# markerSize se refiere a 6x6
def findArucoMarkers(img, markerSize=6, totalMarkers=250, draw=True):
    imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    key = getattr(aruco, f'DICT_{markerSize}X{markerSize}_{totalMarkers}')
    arucoDict = aruco.Dictionary_get(key)
    arucoParam = aruco.DetectorParameters_create()
    bounding_boxes, ids, rejected = aruco.detectMarkers(imgGray, arucoDict, parameters=arucoParam)

    # print(ids)
    if draw:
        aruco.drawDetectedMarkers(img,bounding_boxes)

    return [bounding_boxes, ids]


def augmentAruco(boundingbox, id, img, imgAug, drawId=True):
    # Cogemos las esquinas de la caja
    tl = boundingbox[0][0][0], boundingbox[0][0][1]
    tr = boundingbox[0][1][0], boundingbox[0][1][1]
    br = boundingbox[0][2][0], boundingbox[0][2][1]
    bl = boundingbox[0][3][0], boundingbox[0][3][1]

    h, w, c = imgAug.shape

    pts1 = np.array([tl, tr, br, bl])
    pts2 = np.float32([[0,0],[w,0],[w,h],[0,h]])
    matrix, _ = cv2.findHomography(pts2, pts1)
    imgOut = cv2.warpPerspective(imgAug, matrix, (img.shape[1], img.shape[0]))
    cv2.fillConvexPoly(img, pts1.astype(int), (0,0,0))
    imgOut = img + imgOut

    if drawId:
        cv2.putText(imgOut, str(id), tl, cv2.FONT_HERSHEY_PLAIN, 2, (255, 0, 255), 2)
    
    return imgOut
    


def main():
    cap = cv2.VideoCapture(0)
    imgAug = cv2.imread("lena.tif")
    while True:
        success, img = cap.read()
        arucoFound = findArucoMarkers(img)
    
        # Recorrer todos los marcadores y representar cada uno
        if len(arucoFound[0]) != 0:
            for bounding_box, id in zip(arucoFound[0], arucoFound[1]):
                img = augmentAruco(bounding_box, id, img, imgAug)

        cv2.imshow("Image", img)
        cv2.waitKey(1)

if __name__ == "__main__":
    main()