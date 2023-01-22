#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int i,int j){
    int maxnum,minnum;
    maxnum = max(i,j);
    minnum = min(i,j);
    if(!minnum){
        return maxnum;
    }
    return gcd(maxnum%minnum,minnum);
}
int main(void){
    int a;
    while(cin>>a&&a!=0){
        int G = 0;
        for(int i = 1;i<a;i++){
            for(int j = i+1;j<=a;j++){
                G+=gcd(i,j);
            }
        }
        cout<<G<<endl;
    }

}
// int gcd(int a,int b){
//     int c=max(a,b);
//     int d=min(a,b);
//     if(d==0){return 0;}
//     a=c;
//     b=d;
//     while(b!=0){
//         int mut=a/b;
//         int temp=b;
//         b=a-mut*b;
//         a=temp;
//     }
//     return a;
// }