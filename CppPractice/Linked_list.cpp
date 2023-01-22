#include<iostream>
#include<iomanip>
using namespace std;
void show();
void insert();
void del();
void search();
struct Node{
    char name[20];
    double score;
    Node *link;
};
Node *head,*current,*previous,*ptr;
int main(void){
    head=new Node;
    head->link=NULL;
    char choice;
    cout<<"i:[INSERT]"<<endl;
    cout<<"d:[DELETE]"<<endl;
    cout<<"s:[SHOW]"<<endl;
    cout<<"q:[EXIT]"<<endl;
    cout<<endl;
    while(1){
        cout<<"Please enter option: ";
        cin>>choice;
        switch(choice){
            case 'i':
                insert();
                break;
            case 'd':
                del();
                break;
            case 's':
                show();
                break;
            case 'q':
                cout<<"\nBye Bye!\n";
                exit(1);
            default:
                cout<<"mistake\n\n";
        }
    }
}
void insert(){
    ptr =new Node;
    cout<<"Please enter your name: ";
    cin>>ptr->name;
    cout<<"Please enter your score: ";
    cin>>ptr->score;

    previous =head;
    current =head->link;
    while (current!=NULL&&current->score<ptr->score){
        previous=current;
        current=current->link;
    }
    ptr->link=current;
    previous->link=ptr;
    cout<<"Insert OK"<<endl<<endl;

}
void del(){
    char delName[15];
    cout<<"Please enter the name you want to delete ";
    cin>>delName;
    previous=head;
    current=previous->link;
    while (current!=NULL&&strcmp(current->name,delName)!=0){
        previous=current;
        current=current->link;
    }
    if (current!=NULL){
        previous->link=current->link;
        delete current;
        cout<<delName<<"deleted"<<endl<<endl;
    }
    else{
        cout<<delName<<"dose not exist!"<<endl<<endl;
    }
}
void show(){
    current=head->link;
    cout<<fixed<<setprecision(2);
    cout<<"\nName"<<"       score"<<endl;
    while (current!=NULL){
        cout<<setw(15)<<left<<(*current).name<<setw(6)<<current->score;
        cout<<endl;
    }
    cout<<endl;
}