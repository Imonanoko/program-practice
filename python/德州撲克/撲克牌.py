import random
#抽卡
#0=黑桃，1=紅心，2=方塊，3=梅花
def draw(draw_num):
    card_list =[i for i in range (0,52)]
    random.shuffle(card_list)
    hand=[((card%13),(card//13)) for card in card_list[:int(draw_num)]]
    #print(hand)                                                           
    return hand
def is_straight():#順子
    card_list=draw(5)
    suit_count=[0 for i in range(4)]
    value_count = [0 for i in range(14)]
    for value,suit in card_list:
        value_count[value]+=1
        suit_count[suit]+=1
        if value ==0:
            value_count[13]+=1
    #print(suit_count)
    #print(value_count)
    if 5 in suit_count:
        return False
    for i in range(10):
        for j in range(5):
            if value_count[i+j]==0:
                break
        else:
            #print(suit_count)
            #print(value_count)
            return True
def is_full_house():
    card_list=draw(5)
    value_count=dict()
    for value,suit in card_list:
        if value in value_count:
            value_count[value]+=1
        else:
            value_count[value]=1
    if 3 in value_count.values():
        if 2 in value_count.values():
            return True
    return False
error = {'straight':5/1274,'full_house':6/4145}
mode = int(input('1:順子\n2:葫蘆\n選擇牌形'))
times=int(input('輸入執行次數:'))
count=0
if mode ==1:
    for i in range(times):
        if is_straight():
            count+=1
    print(f'在{times}次測試中，出現了{count}次順子，理論次數約為{(error["straight"]*times):.1f}次')
    print(f"與理論值誤差約{(((count/times)-error['straight'])/error['straight']):.6%}")
if mode ==2:
    for i in range(times):
        if is_full_house:
            count+=1
            print(f'在{times}次測試中，出現了{count}次葫蘆，理論次數約為{(error["full_house"]*times):.1f}次')
            print(f"與理論值誤差約{(((count/times)-error['full_house'])/error['full_house']):.6%}")
