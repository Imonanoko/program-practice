#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int count(string str){
    int i=0;
    while(i<str.length()){
        if(str[i]==' '){
            return i;
        }
        i++;
    }
    return i;
}
struct country{
    string name;
    int counter;
};
bool compare(country a,country b){
    if(a.counter<b.counter){return true;}
    if(a.counter==b.counter){
        if(a.name[0]<=b.name[0]){return true;}
    }
    return false;
}
int main(void){
    int num,counter=0;
    cin>>num;
    country arr[num];
    for(int i=0;i<=num;i++){
        int det=0;
        string str;
        getline(cin,str);
        string ans="";
        for(int k=0;k<count(str);k++){
            ans+=str[k];
        }
        for(int j=0;j<=counter;j++){
            if(arr[j].name==ans){
                arr[j].counter+=1;
                det++;
            }
        }
        if(det==0){
            arr[counter].name=ans;
            arr[counter].counter=1;
            counter++;
        }
    }
    sort(arr,arr+counter,compare);
    for(int i=0;i<counter;i++){
        cout<<arr[i].name<<" "<<arr[i].counter<<endl;
    }
}