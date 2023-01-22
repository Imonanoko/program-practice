x=int(input('Enter a positive integer'))
if x<=2:
    print('fibonacci number:',1)
else:
    a=1
    b=1
    for i in range(x-2):
        y=a+b
        a=b
        b=y
    print('fibonacci number:',y)

