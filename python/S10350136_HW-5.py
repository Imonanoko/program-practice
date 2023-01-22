#利用ASCII碼
#因為在ACSII碼的ABC減3換變成其他的符號，所以用字典先設定好ABC的ASCII碼扣掉65會等於多少
#然後用for迴圈將輸入的字串分成一個一個然後將字母轉成ASCII碼再將數字減3再用chr()將數字轉回文字
#然後用空字串一個一個加在一起，在輸出
D={0:'X',1:'Y',2:'Z'}
x=input("Enter a string of encrypted text:").upper()
w=''
for i in x:
    y=ord(i)
    if y>67:
        w+=chr(y-3)
    else:
        w+=D[y-65]
print(w)
