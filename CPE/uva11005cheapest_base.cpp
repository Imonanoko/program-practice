#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    int test, count = 1;
    cin >> test;
    int det = test;
    while (test--)
    {
        int ary[36];
        for (int i = 0; i < 36; i++)
        {
            cin >> ary[i];
        }
        int time;
        cin >> time;
        cout << "Case " << count << ":" << endl;
        while (time--)
        {
            int a, b;
            cin >> a;
            int cheapest[37] = {0};
            for (int i = 36; i >= 2; i--)
            {
                b = a;
                while (b > 0)
                {
                    cheapest[i] += ary[b % i];
                    b /= i;
                }
            }
            int record = 2;
            int chemin = cheapest[2];
            int save[36] = {0};
            int index = 0;
            for (int i = 2; i <= 36; i++)
            {
                if (chemin >= cheapest[i])
                {
                    chemin = cheapest[i];
                }
            }
            for (int i = 2; i <= 36; i++)
            {
                if (chemin == cheapest[i])
                {
                    save[index] = i;
                    index++;
                }
            }
            cout << "Cheapest base(s) for number " << a << ": ";
            for (int i = 0; i < index - 1; i++)
            {
                cout << save[i] << " ";
            }
            cout << save[index - 1] << endl;
        }
        if (det != count)
        {
            cout << endl;
        }
        count++;
    }
}