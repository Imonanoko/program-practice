#include <iostream>
#include <iomanip>
using namespace std; 
int main(void){
    int score1,score2,score3,score4,score5;
    cout<<"輸入你的C++平時作業、平時考、期中考、期末考，以及上機測試的分數，並以空格分開:";
    cin>>score1>>score2>>score3>>score4>>score5;
    float a=0.2,b=0.25,c=0.15;
    float final_score=(score1+score2+score5)*a+score3*b+score4*c;
    cout<<"你C++最後的分數是"<<final_score;
}