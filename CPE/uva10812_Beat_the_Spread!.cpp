#include <iostream>
using namespace std;
int main(void)
{
    int time, casecounter = 1;
    cin >> time;
    while (time--)
    {
        int a, b, c, d;
        cin >> c >> d;
        if ((c + d) % 2 == 1)
        {
            cout << "impossible" << endl;
        }
        else
        {
            a = (c + d) / 2;
            b = a - d;
            if (a >= 0 && b >= 0)
            {
                cout << max(a, b) << " " << min(a, b) << endl;
            }
            else
            {
                cout << "impossible" << endl;
            }
        }
    }
}