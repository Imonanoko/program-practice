#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
        {
            break;
        }
        int total = 0;
        for (int i = sqrt(a); i <= 320; i++)
        {
            int square = pow(i, 2);
            if (square < b && square > a)
            {
                total++;
            }
            else if (square == a || square == b)
            {
                total++;
            }
            else
            {
                if (square > b)
                {
                    break;
                }
            }
        }
        cout << total << endl;
    }
}