#include<iostream>
using namespace std;
int main(void){
    float gpa;
    cout<<"¿é¤J§Aªºgpa:";
    cin>>gpa;
    if (gpa==4){
        cout<<"excellent student";
    }
    else if (gpa==3){
        cout<<"good student";
    }
    else if (gpa==2){
        cout<<"satisfactory";
    }
    else if (gpa==1){
        cout<<"score = 50";
    }
    else{
        cout<<"are you a fool or a genius";
    }
}