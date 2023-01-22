//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!
#include<iostream>
using namespace std;
int main(void){
	int time;
	cin>>time;
	while(time--){
		int ary[9][9]={0};
		for(int i=0;i<9;i+=2){
			for(int j=0;j<i+1;j+=2){
				cin>>ary[i][j];
			}
		}

	



		for(int i=8;i>=2;i-=2){
			for(int j=1;j<=i/2;j+=2){
				ary[i][j]=(ary[i-2][j-1]-ary[i][j-1]-ary[i][j+1])/2;
			}
		}
		for(int i=7;i>0;i-=2){
			for(int j=0;j<=i+1;j++){
				ary[i][j]=ary[i+1][j]+ary[i+1][j+1];
			}
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<=i;j++){
				cout<<ary[i][j]<<" ";
				if(j==i){
					cout<<ary[i][j]<<endl;
				}
				
			}
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<i+1;j++){
				
				if(j==i){
					cout<<ary[i][j]<<endl;
				}
				else{
					cout<<ary[i][j]<<" ";
				}
				
			}
		}
	}
	}