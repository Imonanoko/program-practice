#include<iostream>
using namespace std;
int main(void){
    string gpa;
    char gpa1;
    cout<<"¿é¤J§Aªºgpa:";
    cin>>gpa;
    cout<<gpa<<endl;
    if (gpa=="1"){gpa1='1';}
    else if ( gpa=="2"){gpa1='2';}
    else if (gpa=="3"){gpa1='3';}
    else if (gpa=="4"){gpa1='4';}
    else{gpa1='5';}
    switch (gpa1)
    {
    case '1':
        cout<<"score = 50"<<endl;
        break;
    case '2':
        cout<<"satisfactory"<<endl;
        break;
    case '3':
        cout<<"good student"<<endl;
        break;
    case '4':
        cout<<"excellent student"<<endl;
        break;
    default:
        cout<<"are you a fool or a genius"<<endl;
        break;
    }
}