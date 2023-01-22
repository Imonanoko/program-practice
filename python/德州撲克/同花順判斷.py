number={'0':10,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
suit={'梅花':1,'方塊':2,'紅心':3,'黑桃':4}
player= [['黑桃', '3'], ['紅心', '3']] 
boss= [['黑桃', '2'], ['方塊', '6']] 
table= [['黑桃', 'J'], ['黑桃', 'K'], ['黑桃', '10'], ['黑桃', '7'], ['黑桃', '9']]
def arrange(player,table):
    total_card=player+table
    y=sorted(total_card,key=lambda x:suit[x[0]])
    x=sorted(y, key=lambda x:number[x[1]])
    return x
hand1=arrange(player, table)
hand2=arrange(boss, table)
def straight_flush(hand1,hand2):
    string='2345678910JQKA2345A'
    x1=[]
    x2=[]
    x3=[]
    x4=[]
    y1=[]
    y2=[]
    y3=[]
    y4=[]
    for i in hand1:
        if suit[i[0]]==1:
            x1+=i
        elif suit[i[0]]==2:
            x2+=i
        elif suit[i[0]]==3:
            x3+=i
        else:
            x4+=i
    for i in hand2:
        if suit[i[0]]==1:
            y1+=i
        elif suit[i[0]]==2:
            y2+=i
        elif suit[i[0]]==3:
            y3+=i
        else:
            y4+=i
    if len(x1)>=10:
        player_flush=x1
    elif len(x2)>=10:
        player_flush=x2
    elif len(x3)>=10:
        player_flush=x3
    elif len(x4)>=10:
        player_flush=x4
    else:
        player_flush=[]
    if len(y1)>=10:
        boss_flush=y1
    elif len(y2)>=10:
        boss_flush=y2
    elif len(y3)>=10:
        boss_flush=y3
    elif len(y4)>=10:
        boss_flush=y4
    else:
        boss_flush=[]
    if player_flush==[] and boss_flush==[]:
        return 1,1
    a='1'
    b='1'
    if len(player_flush)==14:
        for i in range(0,6,2):
            x1=''
            for j in range(i+1,10+i,2):
                x1+=player_flush[j]
            if x1 in string:
                a=x1
    elif len(player_flush)==12:
        for i in range(0,4,2):
            x1=''
            for j in range(i+1,10+i,2):
                x1+=player_flush[j]
            if x1 in string:
                a=x1
    elif len(player_flush)==10:
        x1=''
        for i in range(1,10,2):
            x1+=player_flush[i]
        if x1 in string:
            a=x1
    if len(boss_flush)==14:
        for i in range(0,6,2):
            y1=''
            for j in range(i+1,10+i,2):
                y1+=boss_flush[j]
            if y1 in string:
                b=y1
    elif len(boss_flush)==12:
        for i in range(0,4,2):
            y1=''
            for j in range(i+1,10+i,2):
                y1+=boss_flush[j]
            if y1 in string:
                b=y1
    elif len(boss_flush)==10:
        y1=''
        for i in range(1,10,2):
            y1+=boss_flush[i]
        if y1 in string:
            b=y1
    player=a[-1]
    boss=b[-1]
    if a[-1]=='A':
        if '5A' in a:
            player='5'
    if b[-1]=='A':
        if '5A' in b:
            boss='5'
    if a=="1" and b=='1':
        return 1,1
    elif a!='1' and b=='1':
        return 9,0
    elif a=='1' and b!='1':
        return 0,9
    else:
        if number[player]==number[boss]:
            return 100,100
        elif number[player]>number[boss]:
            return 9,0
        elif number[player]<number[boss]:
            return 0,9


