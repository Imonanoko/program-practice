import cv2

def capFrame(videoPath, savePath):
    cap = cv2.VideoCapture(videoPath)
    numFrame = 0
    num=0
    while True:
        if cap.grab():
            numFrame += 1
            # 每1800楨截取一個圖片
            if numFrame % 1800 == 1:
                #retrieve 解碼並返回一個楨
                flag, frame = cap.retrieve()
                if not flag:
                    continue
                else:
                    num+=1
                    cv2.imshow('video', frame)
                    newPath = savePath + "\\" + str(int(num)) + ".jpg"
                    cv2.imencode('.jpg', frame)[1].tofile(newPath)
        #檢測到按下Esc時，break（和imshow配合使用）
        if cv2.waitKey(10) == 27:
            break
#影片來源，儲存位置
capFrame('C:\\Users\\USER\\Videos\\22-05-09-16-24-52.mp4','C:\\Users\\USER\\Pictures\\社會')