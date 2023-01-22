#include <iostream>
#include <iomanip>
using namespace std;
int main(void)
{
    float x[4], y[4];
    while (cin >> x[0] >> y[0])
    {
        int savei, savej;
        float ansx = 0, ansy = 0;
        for (int i = 1; i < 4; i++)
        {
            cin >> x[i];
            cin >> y[i];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (x[i] == x[j] && y[i] == y[j])
                {
                    savei = i;
                    savej = j;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (i != savei && i != savej)
            {
                ansx += x[i];
                ansy += y[i];
            }
        }
        ansx -= x[savei];
        ansy -= y[savei];
        cout << fixed << setprecision(3) << ansx << " " << ansy << endl;
    }
}