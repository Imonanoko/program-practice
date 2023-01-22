#include <iostream>
using namespace std;
int n, ans=0;
void hanoi(int n, char from, char to, char mid){ //from A, to C, mid B
    if(n == 1){ //只需移1個盤子
        ans++;
        cout<<"[Step "<<ans<<"] Move "<<n<<" from "<<from<<" to "<<to<<"."<<endl;
        return; //結束
    }
    hanoi(n-1, from, mid, to); //把A的n-1個盤子移到B
    ans++;
    cout<<"[Step "<<ans<<"] Move "<<n<<" from "<<from<<" to "<<to<<"."<<endl;
    hanoi(n-1, mid, to, from); //把B的n-1個盤子移到C
    }
int main(){
    cin >> n; //幾個盤子
    hanoi(n, 'A', 'C', 'B');
}