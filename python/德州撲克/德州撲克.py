print('規則最小金額為!最大為10無加註規則也無法all in。賺到400獲勝，在遊戲中可以變成負值')
import random
number={'1':10,'0':10,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,"9":9,'10':10,'J':11,'Q':12,'K':13,'A':14}
suit={'梅花':1,'方塊':2,'紅心':3,'黑桃':4}
outcome={9:'同花順',8:'四條',7:'葫蘆',6:'同花',5:'順子',4:'三條',3:'兩對',2:'一對',1:'高牌',666:'平手',
         0:'同花順',-1:'四條',-2:'葫蘆',-3:'同花',-4:'順子',-5:'三條',-6:'兩對',-7:'一對',-8:'高牌'}
def arrange(player,table):
    total_card=player+table
    y=sorted(total_card,key=lambda x:suit[x[0]])
    x=sorted(y, key=lambda x:number[x[1]])
    return x
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
def straight(hand1,hand2):
    string='2345678910JQKA2345A'
    x=[]
    y=[]
    a='1'
    b='1'
    for i in hand1:
        if i[1] not in x:
            x.append(i[1])
    for i in hand2:
        if i[1] not in y:
            y.append(i[1])
    if len(x)==7:
        for i in range(3):
            x1=''
            for j in range(i,5+i):
                x1+=x[j]
            if x1 in string:
                a=x1
            elif '2345' in x1:
                if 'A' in x:
                    a='5'
    elif len(x)==6:
        for i in range(2):
            x1=''
            for j in range(i,5+i):
                x1+=x[j]
            if x1 in string:
                a=x1
            elif '2345' in x1:
                if 'A' in x:
                    a='5'
    elif len(x)==5:
        x1=''
        for i in range(5):
            x1+=x[i]
        if x1 in string:
            a=x1
        elif '2345' in x1:
            if 'A' in x:
                a='5'
    if len(y)==7:
        for i in range(3):
            y1=''
            for j in range(i,5+i):
                y1+=y[j]
            if y1 in string:
                b=y1
            elif '2345' in y1:
                if 'A' in y:
                    b='5'
    elif len(y)==6:
        for i in range(2):
            y1=''
            for j in range(i,5+i):
                y1+=y[j]
            if y1 in string:
                b=y1
            elif '2345' in y1:
                if 'A' in y:
                    b='5'
    elif len(y)==5:
        y1=''
        for i in range(5):
            y1+=y[i]
        if y1 in string:
            b=y1
        elif '2345' in y1:
            if 'A' in y:
                b='5'
    player=a[-1]
    boss=b[-1]
    if a[-1]=='A':
        if '5A' in a:
            player='5'
    if b[-1]=='A':
        if '5A' in b:
            boss='5'
    if a=="1" and b=='1':
        return 1,1
    elif a!='1' and b=='1':
        return 5,0
    elif a=='1' and b!='1':
        return 0,5
    else:
        if number[player]==number[boss]:
            return 100,100
        elif number[player]>number[boss]:
            return 5,0
        elif number[player]<number[boss]:
            return 0,5
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
def straight_flush(hand1,hand2):
    string='2345678910JQKA2345A'
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
    a='1'
    b='1'
    if len(player_flush)==14:
        for i in range(0,6,2):
            x1=''
            for j in range(i+1,10+i,2):
                x1+=player_flush[j]
            if x1 in string:
                a=x1
    elif len(player_flush)==12:
        for i in range(0,4,2):
            x1=''
            for j in range(i+1,10+i,2):
                x1+=player_flush[j]
            if x1 in string:
                a=x1
    elif len(player_flush)==10:
        x1=''
        for i in range(1,10,2):
            x1+=player_flush[i]
        if x1 in string:
            a=x1
    if len(boss_flush)==14:
        for i in range(0,6,2):
            y1=''
            for j in range(i+1,10+i,2):
                y1+=boss_flush[j]
            if y1 in string:
                b=y1
    elif len(boss_flush)==12:
        for i in range(0,4,2):
            y1=''
            for j in range(i+1,10+i,2):
                y1+=boss_flush[j]
            if y1 in string:
                b=y1
    elif len(boss_flush)==10:
        y1=''
        for i in range(1,10,2):
            y1+=boss_flush[i]
        if y1 in string:
            b=y1
    player=a[-1]
    boss=b[-1]
    if a[-1]=='A':
        if '5A' in a:
            player='5'
    if b[-1]=='A':
        if '5A' in b:
            boss='5'
    if a=="1" and b=='1':
        return 1,1
    elif a!='1' and b=='1':
        return 9,0
    elif a=='1' and b!='1':
        return 0,9
    else:
        if number[player]==number[boss]:
            return 100,100
        elif number[player]>number[boss]:
            return 9,0
        elif number[player]<number[boss]:
            return 0,9
def winer(hand1,hand2):
    x=straight_flush(hand1, hand2)
    if x[0]>x[1]:
        return 9
    elif x[0]<x[1]:
        return 0
    elif x[0]==100:
        return 666
    else:
        x1=four_of_a_kind(hand1, hand2)
        if x1[0]>x1[1]:
            return 8
        elif x1[0]<x1[1]:
            return -1
        elif x1[0]==100:
            return 666
        else:
            x=full_house(hand1, hand2)
            if x[0]>x[1]:
                return 7
            elif x[0]<x[1]:
                return -2
            elif x[0]==100:
                return 666
            else:
                x=flush(hand1, hand2)
                if x[0]>x[1]:
                    return 6
                elif x[0]<x[1]:
                    return -3
                elif x[0]==100:
                    return 666
                else:
                    x=straight(hand1, hand2)
                    if x[0]>x[1]:
                        return 5
                    elif x[0]<x[1]:
                        return -4
                    elif x[0]==100:
                        return 666
                    else:
                        x=three_of_a_kind(hand1, hand2)
                        if x[0]>x[1]:
                            return 4
                        elif x[0]<x[1]:
                            return -5
                        elif x[0]==100:
                            return 666
                        else:
                            x=two_pair(hand1, hand2)
                            if x[0]>x[1]:
                                return 3
                            elif x[0]<x[1]:
                                return -6
                            elif x[0]==100:
                                return 666
                            else:
                                x=one_pair(hand1, hand2)
                                if x[0]>x[1]:
                                    return 2
                                elif x[0]<x[1]:
                                    return -7
                                elif x[0]==100:
                                    return 666
                                else:
                                    x=High_card(hand1, hand2)
                                    if x[0]>x[1]:
                                        return 1
                                    elif x[0]<x[1]:
                                        return -8
                                    elif x[0]==100:
                                        return 666
                                    else:
                                        return 666
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
money=200
while 0<=money<=400:
    computer_give_up=1
    print('your money:',money)
    money-=1
    total_money=2
    x=running()
    boss=[x[0],x[2]]
    player=[x[1],x[3]]
    table=[x[4],x[5],x[6],x[7],x[8]]
    hand1=arrange(player, table)
    hand2=arrange(boss, table)
    print('您的手牌:',player)
    first=eval(input('請下注最大10元輸入0表示棄牌'))
    while first>10:
        first=eval(input('請重新下注最大10元輸入0表示棄牌'))    
    if first>0:
        money-=first
        total_money+=first
        determine=two_card(boss, player)
        if determine[0]>=determine[1]:
            total_money+=first
        elif determine[0]<determine[1]:
            money+=total_money
            print('computer give up:')
            computer_give_up=0
        while computer_give_up!=0 and computer_give_up==1:
            computer_give_up=2
            print('table:',table[0],table[1],table[2])
            second=eval(input('請下注最大10元輸入0表示棄牌'))
            while second>10:
                second=eval(input('請重新下注最大10元輸入0表示棄牌'))
            if second>0:
                money-=second
                total_money+=2*second
                print('table:',table[0],table[1],table[2],table[3])
                third=eval(input('請下注最大10元輸入0表示棄牌'))
                while third>10:
                    third=eval(input('請重新下注最大10元輸入0表示棄牌'))
                if third>0:
                    money-=third
                    total_money+=2*third
                    print('table:',table[0],table[1],table[2],table[3],table[4])
                    four_th=eval(input('請下注最大10元輸入0表示棄牌'))
                    while four_th>10:
                        four_th =eval(input('請重新下注最大10元輸入0表示棄牌'))
                    if four_th>0:
                        money-=four_th
                        total_money+=2*four_th
                        print('player:',player,'\n','boss:',boss,'\n','table:',table)
                        win=winer(hand1, hand2)
                        player_win=[1,2,3,4,5,6,7,8,9]
                        boss_win=[0,-1,-2,-3,-4,-5,-6,-7,-8]
                        if win==666:
                            money+=total_money/2
                            print(outcome[666])
                        elif win in player_win:
                            money+=total_money
                            print('player win:',outcome[win],'\n','\n')
                        elif win in boss_win:
                            print('computer win:',outcome[win],'\n','\n')
if money>400:
    print('you are winner')
elif money<0:
    print('you are loser')
       
                    
                    
                    
                    
                
    
    
    
