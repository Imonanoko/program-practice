#include<iostream>
using namespace std;
char findposition(char p,char cmd){
    if(cmd=='R'){
        if(p=='N'){
                    p='E';
                }
                else if(p=='W'){
                    p='N';
                }
                else if(p=='S'){
                    p='W';
                }
                else if(p=='E'){
                    p='S';
                }
    }
    else{
        if(p=='N'){
                    p='W';
                }
                else if(p=='W'){
                    p='S';
                }
                else if(p=='S'){
                    p='E';
                }
                else if(p=='E'){
                    p='N';
                }
    }
    return p;
}
int main(void){
    int edgeX,edgeY,x,y;
    char position;
    int record[51][51]={0};
    cin>>edgeX>>edgeY;
    while(cin>>x>>y>>position){
        string cmd;
        cin>>cmd;
        for(int i=0;i<cmd.length();i++){
            int tempx=x,tempy=y;
            if(cmd[i]=='F'){
                if(position=='N')tempy++;
                else if(position=='S')tempy--;
                else if(position=='W')tempx++;
                else if(position=='E')tempx--;
                if(tempx>edgeX||tempx<0||tempy>edgeY||tempy<0){
                    if(!record[x][y]){
                        record[x][y]=1;
                        cout<<x<<" "<<y<<" "<<position<<" LOST"<<endl;
                        break;
                    }
                }
                else{
                    x=tempx;
                    y=tempy;
                }
            }
            else{
                position=findposition(position,cmd[i]);
            }
            if(i==cmd.length()-1){
                cout<<x<<" "<<y<<" "<<position<<endl;
            }
        }
    }
}