number={'0':10,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
suit={'梅花':1,'方塊':2,'紅心':3,'黑桃':4}
player= [['黑桃', '10'], ['紅心', '7']] 
boss= [['梅花', 'A'], ['方塊', 'A']] 
table= [['黑桃', 'A'], ['紅心', 'A'], ['紅心', '10'], ['方塊', '10'], ['梅花', '10']]
def arrange(player,table):
    total_card=player+table
    y=sorted(total_card,key=lambda x:suit[x[0]])
    x=sorted(y, key=lambda x:number[x[1]])
    return x
hand1=arrange(player, table)
hand2=arrange(boss, table)
def four_of_a_kind(hand1,hand2):
    x=0
    y=0
    x1=[]
    x2=[]
    for i in hand1:
        for j in hand1:
            for k in hand1:
                for l in hand1:
                    if i!=j and i!=k and i!=l and j!=k and j!=l and k!=l and i[1]==j[1]==k[1]==l[1]:
                        x=number[i[1]]
                        x1.append(i)
    for i in hand2:
        for j in hand2:
            for k in hand2:
                for l in hand2:
                    if i!=j and i!=k and i!=l and j!=k and j!=l and k!=l and i[1]==j[1]==k[1]==l[1]:
                        y=number[i[1]]
                        x2.append(i)
    if x==0 and y==0:
        return 1,1
    elif x!=0 and y==0:
        return 8,0
    elif x==0 and y!=0:                    
        return 0,8
    elif x>y:
        return 8,0
    else:
        return 0,8                
