import csv

with open('calendar2015.csv','w',newline = '') as csvfile:
    file = csv.writer(csvfile)
    D=365
    x=[1,3,5,7,8,10,12]
    for i in range(1,13):
        if i in x:
            for i1 in range(1,32):
                D-=1
                V=D%7
                if V==0:
                    file.writerow(['{}{}{}{}'.format(i,'/',i1,'/2015'),'Tursday'])
                elif V==6:
                    file.writerow(['{}{}{}{}'.format(i,'/',i1,'/2015'),'Fridsy'])
                elif V==5:
                    file.writerow(['{}{}{}{}'.format(i,'/',i1,'/2015'),'Saturday'])
                elif V==4:
                    file.writerow(['{}{}{}{}'.format(i,'/',i1,'/2015'),'Sunday'])
                elif V==3:
                    file.writerow(['{}{}{}{}'.format(i,'/',i1,'/2015'),'Monday'])
                elif V==2:
                    file.writerow(['{}{}{}{}'.format(i,'/',i1,'/2015'),'Tuesday'])
                elif V==1:
                    file.writerow(['{}{}{}{}'.format(i,'/',i1,'/2015'),'Wednesday'])
        elif i==2:
            for i2 in range(1,29):
                D-=1
                V=D%7
                if V==0:
                    file.writerow(['{}{}{}{}'.format(i,'/',i2,'/2015'),'Tursday'])
                elif V==6:
                    file.writerow(['{}{}{}{}'.format(i,'/',i2,'/2015'),'Fridsy'])
                elif V==5:
                    file.writerow(['{}{}{}{}'.format(i,'/',i2,'/2015'),'Saturday'])
                elif V==4:
                    file.writerow(['{}{}{}{}'.format(i,'/',i2,'/2015'),'Sunday'])
                elif V==3:
                    file.writerow(['{}{}{}{}'.format(i,'/',i2,'/2015'),'Monday'])
                elif V==2:
                    file.writerow(['{}{}{}{}'.format(i,'/',i2,'/2015'),'Tuesday'])
                elif V==1:
                    file.writerow(['{}{}{}{}'.format(i,'/',i2,'/2015'),'Wednesday'])
        else:
            for i3 in range(1,31):
                D-=1
                V=D%7
                if V==0:
                    file.writerow(['{}{}{}{}'.format(i,'/',i3,'/2015'),'Tursday'])
                elif V==6:
                    file.writerow(['{}{}{}{}'.format(i,'/',i3,'/2015'),'Fridsy'])
                elif V==5:
                    file.writerow(['{}{}{}{}'.format(i,'/',i3,'/2015'),'Saturday'])
                elif V==4:
                    file.writerow(['{}{}{}{}'.format(i,'/',i3,'/2015'),'Sunday'])
                elif V==3:
                    file.writerow(['{}{}{}{}'.format(i,'/',i3,'/2015'),'Monday'])
                elif V==2:
                    file.writerow(['{}{}{}{}'.format(i,'/',i3,'/2015'),'Tuesday'])
                elif V==1:
                    file.writerow(['{}{}{}{}'.format(i,'/',i3,'/2015'),'Wednesday'])
