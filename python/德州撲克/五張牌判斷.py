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