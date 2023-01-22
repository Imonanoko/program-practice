number={'0':10,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
suit={'梅花':1,'方塊':2,'紅心':3,'黑桃':4}
player=[['方塊', 'J'], ['黑桃', '3']] 
boss=[['黑桃', '2'], ['梅花', 'Q']] 
table= [['紅心', '4'], ['紅心', '5'], ['方塊', '9'], ['方塊', '2'], ['紅心', 'A']]
def arrange(player,table):
    total_card=player+table
    y=sorted(total_card,key=lambda x:suit[x[0]])
    x=sorted(y, key=lambda x:number[x[1]])
    return x
hand1=arrange(player, table)
hand2=arrange(boss, table)
print(hand1)
print(hand2)
def straight(hand1,hand2):
    string='2345678910JQKA2345A'
    x=[]
    y=[]
    a='1'
    b='1'
    for i in hand1:
        if i[1] not in x:
            x.append(i[1])
    for i in hand2:
        if i[1] not in y:
            y.append(i[1])
    print(x)
    print(y)
    if len(x)==7:
        for i in range(3):
            x1=''
            for j in range(i,5+i):
                x1+=x[j]
            if x1 in string:
                a=x1
            elif '2345' in x1:
                if 'A' in x:
                    a='5'
    elif len(x)==6:
        for i in range(2):
            x1=''
            for j in range(i,5+i):
                x1+=x[j]
            if x1 in string:
                a=x1
            elif '2345' in x1:
                if 'A' in x:
                    a='5'
    elif len(x)==5:
        x1=''
        for i in range(5):
            x1+=x[i]
        if x1 in string:
            a=x1
        elif '2345' in x1:
            if 'A' in x:
                a='5'
    if len(y)==7:
        for i in range(3):
            y1=''
            for j in range(i,5+i):
                y1+=y[j]
            if y1 in string:
                b=y1
            elif '2345' in y1:
                if 'A' in y:
                    b='5'
    elif len(y)==6:
        for i in range(2):
            y1=''
            for j in range(i,5+i):
                y1+=y[j]
            if y1 in string:
                b=y1
            elif '2345' in y1:
                if 'A' in y:
                    b='5'
    elif len(y)==5:
        y1=''
        for i in range(5):
            y1+=y[i]
        if y1 in string:
            b=y1
        elif '2345' in y1:
            if 'A' in y:
                b='5'
    player=a[-1]
    boss=b[-1]
    if a=="1" and b=='1':
        return 1,1
    elif a!='1' and b=='1':
        return 5,0
    elif a=='1' and b!='1':
        return 0,5
    else:
        if number[player]==number[boss]:
            return 100,100
        elif number[player]>number[boss]:
            return 5,0
        elif number[player]<number[boss]:
            return 0,5
print(straight(hand1, hand2))
    
        


    
    

        
    
