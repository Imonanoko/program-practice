import random
coin=['T','H']
S=''
for i in range(32):
    x=random.choice(coin)
    S+=x
print(S)
if 'TTTTT' in S or 'HHHHH' in S:
    print('There was a run of five consecutive same outcomes ')
else:
    print('There was no a run of five consecutive same outcomes ')