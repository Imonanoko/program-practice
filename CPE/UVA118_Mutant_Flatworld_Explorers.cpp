#include<iostream>
using namespace std;
int main(void){
    int rangex,rangey,positionX,positionY,repositionx,repositiony;
    char direction;
    string str;
    int record[500];
    int index=0;
    cin>>rangex>>rangey;
    while(cin>>positionX>>positionY>>direction){
        cin>>str;
        int det=1;
        for(int i=0;i<str.length();i++){
            if(str[i]=='R'){
                if(direction=='N'){
                    direction='E';
                }
                else if(direction=='W'){
                    direction='N';
                }
                else if(direction=='S'){
                    direction='W';
                }
                else if(direction=='E'){
                    direction='S';
                }
            }
            if(str[i]=='L'){
                if(direction=='N'){
                    direction='W';
                }
                else if(direction=='W'){
                    direction='S';
                }
                else if(direction=='S'){
                    direction='E';
                }
                else if(direction=='E'){
                    direction='N';
                }
            }
            if(str[i]=='F'){
                if(direction=='N'){
                    positionY++;
                    for(int i=0;i<index;i+=2){
                        if(positionX==record[i]&&positionY==record[i+1]){
                            positionY--;
                            break;
                        }
                    }
                }
                else if(direction=='W'){
                    positionX--;
                    for(int i=0;i<index;i+=2){
                        if(positionX==record[i]&&positionY==record[i+1]){
                            positionX--;
                            break;
                        }
                    }
                }
                else if(direction=='S'){
                    positionY--;
                    for(int i=0;i<index;i+=2){
                        if(positionX==record[i]&&positionY==record[i+1]){
                            positionY++;
                            break;
                        }
                    }
                }
                else if(direction=='E'){
                    positionX++;
                    for(int i=0;i<index;i+=2){
                        if(positionX==record[i]&&positionY==record[i+1]){
                            positionX--;
                            break;
                        }
                    }
                }
                if(positionX>rangex||positionX<0||positionY>rangey||positionY<0){
                    det=0;
                    record[index]=positionX;
                    record[index+1]=positionY;
                    index+=2;
                    break;
                }else{
                    repositionx=positionX;
                    repositiony=positionY;
                }
            }
        }
        if(det){
            cout<<repositionx<<" "<<repositiony<<" "<<direction<<endl;
        }
        else{
            cout<<repositionx<<" "<<repositiony<<" "<<direction<<" LOST"<<endl;
        }
    }
}