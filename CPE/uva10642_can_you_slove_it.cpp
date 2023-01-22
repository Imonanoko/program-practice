#include <iostream>
using namespace std;
int main(void)
{
    int time;
    long long int count = 1;
    cin >> time;
    while (time--)
    {
        int x1, y1, x2, y2, step = 0;
        cin >> y1 >> x1 >> y2 >> x2;
        while (x1 != x2 || y1 != y2)
        {
            if (x1 == 0)
            {
                step++;
                x1 = y1 + 1;
                y1 = 0;
            }
            else
            {
                x1--;
                y1++;
                step++;
            }
        }
        cout << "Case " << count++ << ": " << step << endl;
    }
}