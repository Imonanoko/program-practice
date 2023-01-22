import random
number={'1':10,'0':10,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
def auto():
    pokers=[]
    poker=[]
    for i in ['紅心','黑桃','方塊','梅花']:
        for j in ['A','2','3','4','5','6','7','8','9','10','J','Q','K']:
            poker.append(i)
            poker.append(j)
            pokers.append(poker)
            poker=[]
    return pokers
def running():
    poker= auto()
    random.shuffle(poker)
    x=[]
    for i in range(9):
        x.append(poker[i])
    return x
poker=running()
boss=[poker[0],poker[2]]
player=[poker[1],poker[3]]
table=[poker[4],poker[5],poker[6],poker[7],poker[8]]
def two_card(boss,player):
    one__pair=[]
    combination=[]
    for i in ['2','3','4','5','6','7','8','9','10','J','Q','K','A']:
        for j in ['2','3','4','5','6','7','8','9','10','J','Q','K','A']:
            if i!=j:
                x=i+j
                y=j+i
                if x not in combination:
                    combination.append(y)
            elif i==j:
                x=i+j
                if x not in one__pair:
                    one__pair.append(x)
    c=sorted(one__pair, key=lambda x:number[x[0]])
    d=sorted(combination, key=lambda x:number[x[0]])
    add=d+c
    if number[boss[0][1]]>=number[boss[1][1]]:
        boss_=boss[0][1]+boss[1][1]
    elif number[boss[0][1]]<=number[boss[1][1]]:
        boss_=boss[1][1]+boss[0][1]
    if number[player[0][1]]>=number[player[1][1]]:
        player_=player[0][1]+player[1][1]
    elif number[player[0][1]]<=number[player[1][1]]:
        player_=player[1][1]+player[0][1]
    for i in range(10):
        x1=add[9*i:9*i+9]
        for j in range(10):
            if i==j and boss_ in x1:
                a= j+1
    for i1 in range(10):
        y1=add[9*i1:9*i1+9]
        for j1 in range(10):
            if i1==j1 and player_ in y1:
                b= j1+1
    if boss_=='AA':
        a=10
    elif player_=='AA':
        b=10
    return a,b
print(two_card(boss, player))



















































       

