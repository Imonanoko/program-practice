with open('calendar2015.csv','r') as x:
    with open('calendar2015.txt','w') as y:
            read=x.read()
            y.write(read)
file=open('calendar2015.txt','r')
date=input('Enter a date in 2015:')
for i in file:
    y=i.split(',')
    if y[0] in date:
        print(y[0],y[1])
        
