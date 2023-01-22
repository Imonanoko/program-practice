#include<iostream>
#include<math.h>
using namespace std;
float radius(float,float);
int main(void){
    int time;
    cin>>time;
    for (int i=0;i<time;i++){
        int num=0;
        float arry[num];
        for(int j=0;j<num;j++){
            cin>>arry[num];
        }
    }
}
float radius(float R1,float R2){
    float len,slope,high;
    slope=pow(R1+R2,2);
    high=pow(max(R1,R2)-min(R1,R2),2);
    len=pow(slope-high,1/2);
    return len;
}