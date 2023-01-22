f=open('cowboy.txt','r')
for i in f:
    x=i.split(' ')
    y=[]
    for ee in x:
        if ee not in y:
            y.append(ee)
    if 'Saddle' in y:
        reduce=eval(y[-2])*0.8
        x1=y[-2]
f.close()
f=open('cowboy.txt','rt')
file=open('cowboy2.txt','wt')
for line in f:
    file.write(line.replace(x1,str(reduce)))
file.close()
file=open('cowboy2.txt','r')
print(file.read())
f.close()
file.close()




