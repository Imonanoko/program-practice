#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    int howmanynum;
    while (cin >> howmanynum)
    {
        int ary[howmanynum];
        int detinterval[howmanynum - 1];
        int det=0;
        for (int i = 0; i < howmanynum; i++)
            {
                cin >> ary[i];
            }
        
        if (howmanynum == 1)
        {
            
            cout << "Jolly" << endl;
        }
        else
        {
            
            for (int i = 0; i < howmanynum - 1; i++)
            {
                detinterval[i] = abs(ary[i] - ary[i + 1]);
            }
            sort(detinterval, detinterval + (howmanynum - 1));
            for (int i = 0; i < howmanynum - 1; i++)
            {
                if (detinterval[i] == (i + 1))
                {
                    det=1;
                }
                else{
                    cout<<"Not jolly"<<endl;
                    det = 0;
                    break;
                }
            }
            if(det==1){
                cout << "Jolly" << endl;
            }
        }
    }
}