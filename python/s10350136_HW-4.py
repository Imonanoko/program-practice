x=input().split(' ')#先把輸入的數字用空格分開但裡面都是字串
unsorted=[]
for i in range(len(x)):
   unsorted.append(eval(x[i]))#eval(x[i])是把字串轉成數字，然後存入新的空列表unsorted
for i in range(len(unsorted)):#這個迴圈可以使列表一格一格縮小像課本那樣，以避免找到重複的最小值
    a=unsorted[i:]
    b=a[0]
    for j in range(len(a)):#利用迴圈尋找最小值
        if a[j]<b:
            b=a[j]
    c=unsorted.index(b)#找最小值的位子
    unsorted[i],unsorted[c]=unsorted[c],unsorted[i]#交換最小值與前面的位子
print(unsorted)
    
'''流程:input:23 78 45 8 32 56 將input用空格分開，所以x=['23','78','45','8','32','56']
然後第一個迴圈將字串轉成數字存入unsorted，unsorted=[23, 78, 45, 8, 32, 56]，第二個迴圈
先偵測unsorted的長度，知道我們要跑的次數，i=0時a=[23, 78, 45, 8, 32, 56]，設b為a的第一
個數字以便後面的比大小，b=23，然後裡面的迴圈是偵測a得長度確認要跑幾次，然後讓a的第j個位
子與b比大小誰小就設誰為b(b=8)，找到最小值之後尋找最小值在unsorted的位子(c=3)然後將找到
的位子與第i個位子交換此時unsorted=[8,78,45,23,32,56]，之後換i=1，a=[78,45,23,32,56]，b=78
找到最小值之後(b=23)，c=3，然後第三個位子與第一個位子交換，以此類推。
'''

