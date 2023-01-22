#include <iostream>
using namespace std;
int main(void)
{
    int time;
    string str;
    cin >> time;
    int c[10] = {0, 1, 1, 1, 0, 0, 1, 1, 1, 1};
    int d[10] = {0, 1, 1, 1, 0, 0, 1, 1, 1, 0};
    int e[10] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 0};
    int f[10] = {0, 1, 1, 1, 0, 0, 1, 0, 0, 0};
    int g[10] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    int a[10] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    int b[10] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    int C[10] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    int D[10] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0};
    int E[10] = {1, 1, 1, 1, 0, 0, 1, 1, 0, 0};
    int F[10] = {1, 1, 1, 1, 0, 0, 1, 0, 0, 0};
    int G[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    int A[10] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    int B[10] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    int cur[10] = {0};
    int count[10] = {0};
    getline(cin, str);
    while (time--)
    {
        getline(cin, str);
        for (int i = 0; i < str.length(); i++)
        {
            switch (str[i])
            {
            case 'a':
                for (int i = 0; i < 10; i++)
                {
                    if (a[i] - cur[i] == 1)
                    {
                        count[i]++;
                    }
                    cur[i] = a[i];
                }
                break;
            case 'b':
                for (int i = 0; i < 10; i++)
                {
                    if (b[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = b[i];
                }
                break;
            case 'c':
                for (int i = 0; i < 10; i++)
                {
                    if (c[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = c[i];
                }
                break;
            case 'd':
                for (int i = 0; i < 10; i++)
                {
                    if (d[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = d[i];
                }
                break;
            case 'e':
                for (int i = 0; i < 10; i++)
                {
                    if (e[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = e[i];
                }
                break;
            case 'f':
                for (int i = 0; i < 10; i++)
                {
                    if (f[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = f[i];
                }
                break;
            case 'g':
                for (int i = 0; i < 10; i++)
                {
                    if (g[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = g[i];
                }
                break;
            case 'A':
                for (int i = 0; i < 10; i++)
                {
                    if (A[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = A[i];
                }
                break;
            case 'B':
                for (int i = 0; i < 10; i++)
                {
                    if (B[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = B[i];
                }
                break;
            case 'C':
                for (int i = 0; i < 10; i++)
                {
                    if (C[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = C[i];
                }
                break;
            case 'D':
                for (int i = 0; i < 10; i++)
                {
                    if (D[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = D[i];
                }
                break;
            case 'E':
                for (int i = 0; i < 10; i++)
                {
                    if (E[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = E[i];
                }
                break;
            case 'F':
                for (int i = 0; i < 10; i++)
                {
                    if (F[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = F[i];
                }
                break;
            case 'G':
                for (int i = 0; i < 10; i++)
                {
                    if (G[i] - cur[i] == 1)
                    {
                        count[i] ++;
                    }
                    cur[i] = G[i];
                }
                break;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            cout << count[i];
            if (i != 9)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}