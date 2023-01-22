number={'0':10,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
suit={'梅花':1,'方塊':2,'紅心':3,'黑桃':4}
player= [['紅心', '4'], ['紅心', '3']] 
boss= [['梅花', '4'], ['方塊', '9']] 
table= [['黑桃', '5'], ['紅心', 'Q'], ['黑桃', '3'], ['方塊', '10'], ['黑桃', 'K']]
def arrange(player,table):
    total_card=player+table
    y=sorted(total_card,key=lambda x:suit[x[0]])
    x=sorted(y, key=lambda x:number[x[1]])
    return x
hand1=arrange(player, table)
hand2=arrange(boss, table)
#print(hand1)
#print(hand2)
def one_pair(hand1,hand2):
    pair_num_player=1
    pair_num_boss=1
    for i in hand1:
        for j in hand1:
            if i != j and i[1]==j[1]:
                pair_num_player=number[i[1]]
    for i in hand2:
        for j in hand2:
            if i != j and i[1]==j[1]:
                pair_num_boss=number[i[1]]
    if pair_num_player>pair_num_boss:
        return 2,0
    elif pair_num_player<pair_num_boss:
        return 0,2
    elif pair_num_player==1 and pair_num_boss==1:
        return 1,1
    else:
        x=[]
        y=[]
        for i in hand1:
            if number[i[1]]!=pair_num_player:
                x+=i
        for i in hand2:
            if number[i[1]]!=pair_num_boss:
                y+=i
        if number[x[-1]]>number[y[-1]]:
            return 2,0
        elif number[x[-1]]<number[y[-1]]:
            return 0,2
        else:
            if number[x[-3]]>number[y[-3]]:
                return 2,0
            elif number[x[-3]]<number[y[-3]]:
                return 0,2
            else:
                if number[x[-5]]>number[y[-5]]:
                    return 2,0
                elif number[x[-5]]<number[y[-5]]:
                    return 0,2
                else:
                    return 100,100
x=one_pair(hand1, hand2)
print(x)
'''hand1是玩家，hand2是電腦reture(100,100)=平手，(2,0)=玩家贏，(0,2)=電腦贏，(1,1)=到下一個判斷層
'''            
    