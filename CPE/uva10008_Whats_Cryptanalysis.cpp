#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
struct alpha{//儲存資料
    char word;
    int count;
};
bool compare(alpha a,alpha b){//sort比大小
    if(a.count>b.count){return true;}
    else if(a.count<b.count){return false;}
    else if(a.word<b.word){return true;}
    else{return false;}

}
int main(void){
    alpha a[26];
    for(int i=0;i<26;i++){
        a[i].word=(char)(65+i);
        a[i].count=0;
    }
    int num;
    cin>>num;
    for(int i=0;i<=num;i++){
        char str[1000];
        cin.getline(str,1000,'\n');//可不用"\n"
        for(int j=0;j<strlen(str);j++){//將每個資料儲存
            int word;
            if(isalpha(str[j])){
                if(isupper(str[j])){
                    word=(int)(str[j]-65);
                    a[word].count++;
                }
                else{
                    word=(int)(str[j]-97);
                    a[word].count++;
                    }
            }
        }

    }
    sort(a,a+26,compare);
    for(int i=0;i<26;i++){//把有的英文字輸出
        if(a[i].count==0){break;}
        else{cout<<a[i].word<<" "<<a[i].count<<endl;}
    }
}
