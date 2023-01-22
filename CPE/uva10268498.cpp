#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main(void)
{
    int a;
    while (cin >> a)
    {
        int s[500];
        long long sum = 0;
        int index = 0,b;
        while (cin >> b)
        {
            s[index++] = b;
            char ch = getchar(); //通過getchar()來判斷最後輸入回車符結束
            if (ch == '\n')
                break;
        }
        index-=1;
        // 微分
        for (int i = 0;i<index;i++)
        {
            sum+=(index-i)*s[i]*pow(a,index-i-1);

        }
        cout << sum << endl;
    }
}
// int main(void)
// {
//     long long int x;
//     while(cin>>x){
//         cin.ignore();
//         string coef;
//         getline(cin,coef);
//         string ans="";
//         int deg=0;
//         for(int i = 0;i<coef.length();i++){
//             if(coef[i]==' '){
//                 deg++;
//             }
//         }
//         long long int ary[deg+1];
//         long long int index=0;
//         for(int i = 0;i<coef.length();i++){
//             if(coef[i]!=' '){
//                 ans+=coef[i];
//             }
//             else{
//                 ary[index]=atoi(ans.c_str());
//                 index++;
//                 ans="";
//             }
//         }
//         long long int slope=ary[index-1];
//         int time=2;
//         if(index==0){
//             cout<<0<<endl;
//         }
//         else if(index==1){
//             cout<<slope<<endl;
//         }
//         else{
//         for(int i=index-2;i>=0;i--){
//             slope+=ary[i]*x*time;
//             x*=x;
//             time++;
//         }
//         cout<<slope<<endl;}
//     }
// }
