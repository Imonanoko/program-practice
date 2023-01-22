#include <iostream>
#include<string>
using namespace std;
int main(void)
{
    int a;
    while (cin >> a)
    {
        int save=a;
        if (a == 0)
        {
            break;
        }
        int total = 0;
        string ans = "";
        while (a > 0)
        {   
            int mod=a%2;
            total+=mod;
            if(mod==1){
                ans = "1"+ ans;
            }
            else{
                ans = "0"+ans;
            }
            a /= 2;
        }
        cout << "The parity of "<<ans<<" is "<<total<<" (mod 2)."<<endl;
    }
}