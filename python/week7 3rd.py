file=open('Order,txt','w')
file.writelines(['3\n','2\n','10\n','1\n','4\n'])
file.close
file=open('Order,txt','r')
x=open('cowboy.txt','r')
z1=[]
for line in x:
    y=line.split(' ')
    z=[]
    for i in y:
        if i not in z:
            z.append(i)
    z1.append(z[-2])
del z1[0]
x.close
z2=[]
for line1 in file:
    z2.append(line1)
file.close
z4=[]
for i in z2:
    zzz=[]
    a=''
    for x in i:
        zzz.append(x)
    del zzz[-1]
    for i in range(len(zzz)):
        a+=zzz[i]
    z4.append(a)    
z3=[]
for i in range(len(z1)):
    a=round(eval(z1[i])*eval(z2[i]),2)
    z3.append(a)
total=sum(z3)
file=open('cowboy.txt','r')
zz=[]
for i in file:
    a=file.readline(20)
    zz.append(a)
for i in range(len(z1)):
    print(z4[i],zz[i],':',z3[i])
print('total:',total)


    
