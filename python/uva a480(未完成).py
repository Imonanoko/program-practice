p1=input('Enter a position one:').split(' ')
p2=input('Enter a position two:').split(' ')
city=int(input('Enter have how many city:'))
city1=city
P1=[]
P2=[]
distance1=[]
distance2=[]
distance3=[]
for i in p1:
    P1.append(eval(i))
for i in p2:
    P2.append(eval(i))
P3=[]
while city>0:
   city-=1
   p3=[]
   x=input('Enter position of citys:').split(' ')
   for i in x:
       p3.append(eval(i))
   P3.append(p3)  
for i in range(city1):
    length1=((P1[0]-P3[i][0])**2+(P1[1]-P3[i][1])**2)
    length2=((P2[0]-P3[i][0])**2+(P2[1]-P3[i][1])**2)
    if length1 < length2:
        distance1.append(length1)
    elif length1 > length2:
        distance2.append(length2)
    else:
        distance3.append(length1)
if distance1==[]:
    R1=0
else:
    R1=max(distance1)
if distance2==[]:
    R2=0
else:
    R2=max(distance2)
if distance3==[]:
    R3=0
else:
    R3=max(distance3)
while R3>=R1 and R3>=R2:
    if R1>R2:
        R1=R3
    else:
        R2=R3
    break
outcome=R1+R2
print(outcome)
    

    
    
