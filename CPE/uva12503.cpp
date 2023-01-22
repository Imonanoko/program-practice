#include<iostream>
using namespace std;
int main(void){
	int time;
	string str;
	cin>>time;
	while(time--){
		int time1;
		cin>>time1;
		int p=0,index=0;
		int ary[101];
		while(time1--){
			cin>>str;
			if(str=="LEFT"){
				p-=1;
				index++;
				ary[index]=-1;
			}
			else if(str=="RIGHT"){
				p+=1;
				index++;
				ary[index]=1;
			}
			else{
				int ins;
				cin>>str>>ins;
				p+=ary[ins];
                index++;
				ary[index]=ary[ins];
			}
		}
		cout<<p<<endl;
	}
}