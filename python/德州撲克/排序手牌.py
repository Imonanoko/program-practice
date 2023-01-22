number={'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
suit={'梅花':1,'方塊':2,'紅心':3,'黑桃':4}
player= [['黑桃', '9'], ['紅心', 'Q']] 
boss= [['紅心', '10'], ['方塊', '7']] 
table= [['黑桃', '5'], ['紅心', '2'], ['紅心', '3'], ['方塊', 'K'], ['梅花', '2']]
def arrange(player,table):
    total_card=player+table
    y=sorted(total_card,key=lambda x:suit[x[0]])
    x=sorted(y, key=lambda x:number[x[1]])
    return x

