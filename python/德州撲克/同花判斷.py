number={'0':10,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
suit={'梅花':1,'方塊':2,'紅心':3,'黑桃':4}
player= [['黑桃', '2'], ['紅心', '3']] 
boss= [['黑桃', 'Q'], ['方塊', '6']] 
table= [['黑桃', 'J'], ['黑桃', 'K'], ['黑桃', '10'], ['黑桃', '8'], ['梅花', '9']]
def arrange(player,table):
    total_card=player+table
    y=sorted(total_card,key=lambda x:suit[x[0]])
    x=sorted(y, key=lambda x:number[x[1]])
    return x
hand1=arrange(player, table)
hand2=arrange(boss, table)
def flush(hand1,hand2):
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
    elif player_flush!=[] and boss_flush==[]:
        return 6,0
    elif player_flush==[] and boss_flush!=[]:
        return 0,6
    else:
        if number[player_flush[-1]]>number[boss_flush[-1]]:
            return 6,0
        elif number[player_flush[-1]]<number[boss_flush[-1]]:
            return 0,6
        else:
            if number[player_flush[-3]]>number[boss_flush[-3]]:
                return 6,0
            elif number[player_flush[-3]]<number[boss_flush[-3]]:
                return 0,6
            else:
                if number[player_flush[-5]]>number[boss_flush[-5]]:
                    return 6,0
                elif number[player_flush[-5]]<number[boss_flush[-5]]:
                    return 0,6
                else:
                    if number[player_flush[-7]]>number[boss_flush[-7]]:
                        return 6,0
                    elif number[player_flush[-7]]<number[boss_flush[-7]]:
                        return 0,6
                    else:
                        if number[player_flush[-9]]>number[boss_flush[-9]]:
                            return 6,0
                        elif number[player_flush[-9]]<number[boss_flush[-9]]:
                            return 0,6
                        else:
                            return 100,100          
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    