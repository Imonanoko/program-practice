#include <iostream>
#include<algorithm>
using namespace std;
int main(void)
{
    int num;
    while (cin >> num)
    {
        int ary[num], mid,mid2,count = 0,D;
        for (int i = 0; i < num; i++)
        {
            cin >> ary[i];
        }
        sort(ary,ary+num);
        mid = ary[(num-1)/2];
        mid2 = ary[num/2];
        for(int i = 0 ;i<num;i++){
            if(mid==ary[i]||mid2==ary[i]){
                count++;
            }
        }
        D = mid2-mid+1;
        cout<<mid<<" "<<count<<" "<<D<<endl;
    }
}