import cv2

image = cv2.imread("checkerboard.jpg")
dimensions = image.shape
y=0
x=0
h=100
w=200
crop = image[y:1, x:x+dimensions[1]]
cv2.imshow('Image', crop)
cv2.waitKey(0) 
cv2.destroyWindow("Image")