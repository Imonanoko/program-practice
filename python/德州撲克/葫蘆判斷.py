number={'0':10,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
suit={'梅花':1,'方塊':2,'紅心':3,'黑桃':4}
player= [['黑桃', '6'], ['紅心', 'Q']] 
boss= [['梅花', '5'], ['方塊', '5']] 
table= [['方塊', 'A'], ['梅花', 'J'], ['紅心', '5'], ['方塊', '10'], ['梅花', '6']]
def arrange(player,table):
    total_card=player+table
    y=sorted(total_card,key=lambda x:suit[x[0]])
    x=sorted(y, key=lambda x:number[x[1]])
    return x
hand1=arrange(player, table)
hand2=arrange(boss, table)
print(hand1)
print(hand2)
def full_house(hand1,hand2):
    three_player=[]
    three_boss=[]
    two_player=[]
    two_boss=[]
    for i in hand1:
        for j in hand1:
            for k in hand1:
                if i!=j and i!=k and j!=k and i[1]==j[1] and i[1]==k[1] and j[1]==k[1]:
                    three_player.append(i)
    for i in hand2:
        for j in hand2:
            for k in hand2:
                if i!=j and i!=k and j!=k and i[1]==j[1] and i[1]==k[1] and j[1]==k[1]:
                    three_boss.append(i)
    for i in hand1:
        if i not in three_player:
            two_player.append(i)
    for i in hand2:
        if i not in three_boss:
            two_boss.append(i)
    pair_num_player=1
    pair_num_boss=1
    for i in two_player:
        for j in two_player:
            if i != j and i[1]==j[1]:
                pair_num_player=number[i[1]]
    for i in two_boss:
        for j in two_boss:
            if i != j and i[1]==j[1]:
                pair_num_boss=number[i[1]]
    if (three_player==[] or pair_num_player==1) and (three_boss==[] or pair_num_boss==1):
        return 1,1
    elif (three_player!=[] and pair_num_player!=1) and (three_boss==[] or pair_num_boss==1):
        return 7,0
    elif (three_player==[] or pair_num_player==1) and (three_boss!=[] and pair_num_boss!=1):
        return 0,7
    else:
        if number[three_player[1][1]]>number[three_boss[1][1]]:
            return 7,0
        elif number[three_player[1][1]]<number[three_boss[1][1]]:
            return 0,7
        else:
            if pair_num_player>pair_num_boss:
                return 7,0
            elif pair_num_player<pair_num_boss:
                return 0,7
            else:
                return 100,100
#print(full_house(hand1, hand2))
                
            