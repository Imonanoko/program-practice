#include <iostream>
using namespace std;
int fib(int);
int findmax(int a)
{
    int N = 1;
    while (fib(N) <= a)
    {
        N++;
    }
    N--;
    return N;
}
int fib(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    return fib(n - 1) + fib(n - 2);
}
int main(void)
{
    int time;
    cin >> time;
    while (time--)
    {
        int a;
        cin >> a;
        int save = a;
        int maxdigit = findmax(a);
        string ans = "";
        for (int i = maxdigit; i > 0; i--)
        {
            if (a >= fib(i))
            {
                a -= fib(i);
                ans += "1";
            }
            else
            {
                ans += "0";
            }
        }
        cout << save << " = " << ans << " (fib)" << endl;
    }
}