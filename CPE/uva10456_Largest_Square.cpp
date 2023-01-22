#include<iostream>
using namespace std;
int main(void){
    int time;
    cin>>time;
    while(time--){
        int M,N,Q;
        cin>>M>>N>>Q;
        string ary[M];
        for(int i = 0;i<M;i++){
            cin>>ary[i];
        }
        cout<<M<<" "<<N<<" "<<Q<<endl;
        while(Q--){
            int r,c;
            cin>>r>>c;
            int largestsquare = 1;
            int maxsquare = min(min(r,M-r-1),min(c,N-c-1));
            for(int i = 1 ;i <=maxsquare;i++){
                int det = 1;
                for(int j = r-i;j<=r+i;j++){
                    for(int k = c-i;k<=c+i;k++){
                        if(ary[j][k]!=ary[r][c]){
                            det = 0;
                            break;
                        }
                    }
                }
                if(det){
                    largestsquare+=2;
                }
                else{
                    break;
                }
            }
            cout<<largestsquare<<endl;
        }
    }
}