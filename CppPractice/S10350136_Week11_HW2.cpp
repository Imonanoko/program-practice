#include<iostream>
using namespace std;
template <typename T> void selectionsort(T data [],int n){
    T temp,min;
    int loc;
    for(int i=0;i<n-1;i++)
    {
        min=data[i];
        loc=i;
        for(int j=i+1;j<n;j++)
        {
            if(min>data[j])
            {
                min=data[j];
                loc=j;
            }
        }
 
        temp=data[i];
        data[i]=data[loc];
        data[loc]=temp;
    }
}
int main(void){
    string datas[10];
    int datai[10],num;
    float dataf[10];
    cout<<"data of string enter[1]"<<endl<<"data of int enter[2]"<<endl<<"data of float enter[3]"<<endl;
    cin>>num;
    switch(num){
        case 1:
            for(int i=0;i<10;i++){
                cin>>datas[i];
            }
            selectionsort(datas,10);
            for(int i=0;i<10;i++){
                cout<<datas[i]<<" ";
            }
            break;
        case 2:
            for(int i=0;i<10;i++){
                cin>>datai[i];
            }
            selectionsort(datai,10);
            for(int i=0;i<10;i++){
                cout<<datai[i]<<" ";
            }
            break;
        case 3:
            for(int i=0;i<10;i++){
                cin>>dataf[i];
            }
            selectionsort(dataf,10);
            for(int i=0;i<10;i++){
                cout<<dataf[i]<<" ";
            }
            break;

    }
}