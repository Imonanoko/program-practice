number={'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
suit={'梅花':1,'方塊':2,'紅心':3,'黑桃':4}
player= [['梅花', '6'], ['黑桃', '5']] 
boss= [['紅心', 'K'], ['紅心', '6']] 
table= [['紅心', '3'], ['紅心', 'A'], ['紅心', '2'], ['黑桃', 'J'], ['方塊', '4']]
def arrange(player,table):
    total_card=player+table
    y=sorted(total_card,key=lambda x:suit[x[0]])
    x=sorted(y, key=lambda x:number[x[1]])
    return x
hand1=arrange(player, table)
hand2=arrange(boss, table)
def High_card(hand1,hand2):
    if number[hand1[-1][1]]>number[hand2[-1][1]]:
        return 1,0
    elif number[hand1[-1][1]]<number[hand2[-1][1]]:
        return 0,1
    else:
        if number[hand1[-2][1]]>number[hand2[-2][1]]:
            return 1,0
        elif number[hand1[-2][1]]<number[hand2[-2][1]]:
            return 0,1
        else:
            if number[hand1[-3][1]]>number[hand2[-3][1]]:
                return 1,0
            elif number[hand1[-3][1]]<number[hand2[-3][1]]:
                return 0,1
            else:
                if number[hand1[-4][1]]>number[hand2[-4][1]]:
                    return 1,0
                elif number[hand1[-4][1]]<number[hand2[-4][1]]:
                    return 0,1
                else:
                    if number[hand1[-5][1]]>number[hand2[-5][1]]:
                        return 1,0
                    elif number[hand1[-5][1]]<number[hand2[-5][1]]:
                        return 0,1
                    else:
                        return 100,100
#print(hand1,'\n',hand2)
#print(High_card(hand1, hand2))
'''hand1是玩家，hand2是電腦reture(100,100)=平手，(1,0)=玩家贏，(0,1)=電腦贏
'''
        
