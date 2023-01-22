number={'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
suit={'梅花':1,'方塊':2,'紅心':3,'黑桃':4}
player= [['黑桃', '10'], ['紅心', 'Q']] 
boss= [['紅心', '10'], ['方塊', 'A']] 
table= [['黑桃', '5'], ['紅心', 'A'], ['紅心', '7'], ['方塊', '10'], ['梅花', '2']]
def arrange(player,table):
    total_card=player+table
    y=sorted(total_card,key=lambda x:suit[x[0]])
    x=sorted(y, key=lambda x:number[x[1]])
    return x
hand1=arrange(player, table)
hand2=arrange(boss, table)
def two_pair(hand1,hand2):
    pair_num_player=[]
    pair_num_boss=[]
    for i in hand1:
        for j in hand1:
            if i != j and i[1]==j[1]:
                pair_num_player.append(i)
    for i in hand2:
        for j in hand2:
            if i != j and i[1]==j[1]:
                pair_num_boss.append(i)
    if len(pair_num_player) ==4 and len(pair_num_boss)==4:
        if number[pair_num_player[-1][1]]>number[pair_num_boss[-1][1]]:
            return 3,0
        elif number[pair_num_player[-1][1]]<number[pair_num_boss[-1][1]]:
            return 0,3
        elif number[pair_num_player[-1][1]]==number[pair_num_boss[-1][1]]:
            if number[pair_num_player[-3][1]]>number[pair_num_boss[-3][1]]:
                return 3,0
            elif number[pair_num_player[-3][1]]<number[pair_num_boss[-3][1]]:
                return 0,3
            elif number[pair_num_player[-3][1]]==number[pair_num_boss[-3][1]]:
                return 100,100
    elif len(pair_num_player) ==4 and len(pair_num_boss)!=4:
        return 3,0
    elif len(pair_num_player) !=4 and len(pair_num_boss)==4:
        return 0,3
    else:
        return 1,1
'''print(hand1)
print(hand2)
print(two_pair(hand1, hand2))'''