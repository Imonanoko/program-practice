#include<iostream>
#include<iomanip>
using namespace std;
#define SIZE 10
void list(int *,int);
void add_20(int *,int);
void minus_1(int *,int );
int sum(int *,int );
int main(void){
    int array[SIZE]={1,2,3,4,5,6,7,8,9,10};
    cout<<"The source array: ";
    list (array,SIZE);
    add_20(array,SIZE);
    cout<<"\nAfter adding 20: ";
    list (array,SIZE);
    minus_1(array,SIZE);
    cout<<"\nThen minus 1: ";
    list(array,SIZE);
    cout<<"\nSum of the elements :"<<sum(array,SIZE);
    cout<<endl;
}
void list(int *ary1,int size){
    int i;
    cout<<endl;
    for(i=0;i<size;i++){
        cout<<setw(5)<<*(ary1+i);
        if (((i+1)%5)==0){
            cout<<endl;
        }
    }
}
void add_20(int *ary2,int size){
    int i;
    for(i=0;i<size;i++){
        *(ary2+i)+=20;
    }
}
void minus_1(int *ary3,int size){
    int i;
    for (i=0;i<size;i++){
        --(*ary3++);
    }
}
int sum(int *ary4,int size){
    int i,total=0;
    for (i=0;i<size;i++){
        total+=ary4[i];
    }
    return total;
}
    

