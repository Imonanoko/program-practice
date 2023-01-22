#include <iostream>
#include <algorithm>   
using namespace std;
int main(void){
    int num,num1;
    cin>>num;
    while(num--){
        cin>>num1;
        int arr[500];
        for(int i=0;i<num1;i++){
            cin>>arr[i];
        }
        sort(arr,arr+num1);
        int mid=num1/2;
        int total=0;
        for(int i=0;i<num1;i++){
            total+=abs(arr[i]-arr[mid]);
        }
        cout<<total<<endl;
    }
}
//abs函數不知道為啥vs不能用