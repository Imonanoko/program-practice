#include <iostream>
using namespace std;
int main(void)
{
    int time;
    string str;
    cin >> time;
    getline(cin, str);
    while (time--)
    {
        getline(cin, str);
        int count[10]={0};
        bool finger[10] = {0};
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'c')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i] & i != 0 & i != 4 & i != 5)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[0] = 0;
                finger[4] = 0;
                finger[5] = 0;
            }
            if (str[i] == 'd')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i] & i != 0 & i != 4 & i != 5 & i != 9)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[0] = 0;
                finger[4] = 0;
                finger[5] = 0;
                finger[9] = 0;
            }
            if (str[i] == 'e')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i] & i != 0 & i != 4 & i != 5 & i != 9 & i != 8)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[0] = 0;
                finger[4] = 0;
                finger[5] = 0;
                finger[9] = 0;
                finger[8] = 0;
            }
            if (str[i] == 'f')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i] & i != 0 & i != 4 & i != 5 & i != 9 & i != 8 & i != 7)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[0] = 0;
                finger[4] = 0;
                finger[5] = 0;
                finger[9] = 0;
                finger[8] = 0;
                finger[7] = 0;
            }
            if (str[i] == 'g')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i] & i != 0 & i != 4 & i != 5 & i != 9 & i != 8 & i != 7 & i != 6)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[0] = 0;
                finger[4] = 0;
                finger[5] = 0;
                finger[9] = 0;
                finger[8] = 0;
                finger[7] = 0;
                finger[6] = 0;
            }
            if (str[i] == 'a')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i] & i != 0 & i != 4 & i != 5 & i != 9 & i != 8 & i != 7 & i != 6&i!=3)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[0] = 0;
                finger[4] = 0;
                finger[5] = 0;
                finger[9] = 0;
                finger[8] = 0;
                finger[7] = 0;
                finger[6] = 0;
                finger[3] = 0;
            }
            if (str[i] == 'b')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i] & i != 0 & i != 4 & i != 5 & i != 9 & i != 8 & i != 7 & i != 6&i!=3&i!=2)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[0] = 0;
                finger[2] = 0;
                finger[3] = 0;
                finger[4] = 0;
                finger[6] = 0;
                finger[5] = 0;
                finger[9] = 0;
                finger[8] = 0;
                finger[7] = 0;
            }
            if (str[i] == 'C')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i] & i != 0 & i != 4 & i != 5 & i != 9 & i != 8 & i != 7 & i != 6&i!=3&i!=1)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[0] = 0;
                finger[1] = 0;
                finger[3] = 0;
                finger[4] = 0;
                finger[6] = 0;
                finger[5] = 0;
                finger[9] = 0;
                finger[8] = 0;
                finger[7] = 0;
            }
            if (str[i] == 'D')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i]  & i != 4 & i != 5 & i != 9 )
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[4] = 0;
                finger[5] = 0;
                finger[9] = 0;
            }
            if (str[i] == 'E')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i]  & i != 4 & i != 5 & i != 9 &i!=8)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[4] = 0;
                finger[5] = 0;
                finger[8] = 0;
                finger[9] = 0;
            }
            if (str[i] == 'F')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i]  & i != 4 & i != 5 & i != 9 &i!=8&i!=7)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[4] = 0;
                finger[5] = 0;
                finger[7] = 0;
                finger[8] = 0;
                finger[9] = 0;
            }
            if (str[i] == 'G')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i]  & i != 4 & i != 5 & i != 9 &i!=8&i!=7&i!=6)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[4] = 0;
                finger[5] = 0;
                finger[6] = 0;
                finger[7] = 0;
                finger[8] = 0;
                finger[9] = 0;
            }
            if (str[i] == 'A')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i]  & i != 4 & i != 5 & i != 9 &i!=8&i!=7&i!=6&i!=3)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[3] = 0;
                finger[4] = 0;
                finger[5] = 0;
                finger[6] = 0;
                finger[7] = 0;
                finger[8] = 0;
                finger[9] = 0;
            }
            if (str[i] == 'B')
            {
                for (int i = 0; i < 10; i++)
                {
                    if (!finger[i]  & i != 4 & i != 5 & i != 9 &i!=8&i!=7&i!=6&i!=3&i!=2)
                    {
                        finger[i] = 1;
                        count[i]++;
                    }
                }
                finger[2] = 0;
                finger[3] = 0;
                finger[4] = 0;
                finger[5] = 0;
                finger[6] = 0;
                finger[7] = 0;
                finger[8] = 0;
                finger[9] = 0;
            }
        }
        for(int i = 0;i<10;i++){
            cout<<count[i];
            if(i!=9){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}