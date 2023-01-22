D={'01':1,'02':2,'03':3,'04':4,'05':5,'06':6,'07':7,'08':8,'09':9}
while True:
    x=input()
    v0=0
    s0=0
    D=0
    h,m,s=x.split(':')
    y=s
    if len(s)>2:
        s,v1=s.split(' ')
        try:
            s=D[s]
            m=D[m]
            h=D[h]
        except:
            s=eval(s)
            m=eval(m)
            h=eval(h)
    s1=3600*h+60*m+s
    D+=v0*(s1-s0)/3600
    s0=s1
    if len(s)==2:
        print(h,':',m,':',y,D)
    else:
        continue
    break
    

    
    
