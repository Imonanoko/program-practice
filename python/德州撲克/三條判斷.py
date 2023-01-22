number={'0':10,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
suit={'梅花':1,'方塊':2,'紅心':3,'黑桃':4}
player= [['黑桃', 'A'], ['紅心', 'Q']] 
boss= [['紅心', '5'], ['方塊', 'Q']] 
table= [['黑桃', '5'], ['梅花', '10'], ['紅心', '3'], ['方塊', '10'], ['梅花', '5']]
def arrange(player,table):
    total_card=player+table
    y=sorted(total_card,key=lambda x:suit[x[0]])
    x=sorted(y, key=lambda x:number[x[1]])
    return x
hand1=arrange(player, table)
hand2=arrange(boss, table)
def three_of_a_kind(hand1,hand2):
    three_player=[]
    three_boss=[]
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
    x=[]
    y=[]
    for i in hand1:
        if i not in three_player:
            x.append(i)
    for i in hand2:
        if i not in three_boss:
            y.append(i)
    if len(three_player)==6 and len(three_boss)==6:
        if number[three_player[0][1]]>number[three_boss[0][1]]:
            return 4,0
        elif number[three_player[0][1]]<number[three_boss[0][1]]:
            return 0,4
        elif number[three_player[0][1]]==number[three_boss[0][1]]:
            if number[x[-1][1]]>number[y[-1][1]]:
                return 4,0
            elif number[x[-1][1]]<number[y[-1][1]]:
                return 0,4
            else:
                if number[x[-2][1]]>number[y[-2][1]]:
                    return 4,0
                elif number[x[-2][1]]<number[y[-2][1]]:
                    return 0,4
                else:
                    return 100,100
    elif len(three_player)>len(three_boss):
        return 4,0
    elif len(three_player)<len(three_boss):
        return 0,4
    else:
        return 1,1
'''print(hand1)
print(hand2)
print(three_of_a_kind(hand1,hand2))'''            
                    
                    
                    
                    

