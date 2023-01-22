#include <iostream>
using namespace std;
int main(void)
{
    int r, c;
    string str;
    int count = 0;
    int det = 0;
    while (cin >> r >> c)
    {
        if(r==0&&c==0){
            break;
        }
        if(det){
cout<<endl;
        }
        det=1;
        cout<<"Field #"<<++count<<":"<<endl;
        char ary[r+2][c+2];
        int ans[r+2][c+2] = {0};
        for (int i = 1; i < r+1; i++)
        {
            cin >> str;
            for (int j = 1; j < c+1; j++)
            {
                ary[i][j] = str[j-1];
            }
        }
        for (int i = 1; i < r+1; i++)
        {
            for (int j = 1; j < c+1; j++)
            {
               if(ary[i][j]=='*'){
                    ans[i-1][j-1]++;
                    ans[i-1][j]++;
                    ans[i-1][j+1]++;
                    ans[i][j-1]++;
                    ans[i][j+1]++;
                    ans[i+1][j-1]++;
                    ans[i+1][j]++;
                    ans[i+1][j+1]++;
               }
            }
        }
        for (int i = 1; i < r+1; i++)
        {
            for (int j = 1; j < c+1; j++)
            {
                if (ary[i][j] == '*')
                {
                    cout<<'*';
                }
                else{
                    cout<<ans[i][j];
                }
            }
            cout<<endl;
        }
    }
}