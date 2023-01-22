#include<iostream>
using namespace std;
struct queue{
    int data;
    queue *link;
};
queue *head,*current,*pervious,*ptr;
void add(){
    ptr=new queue;
    cout<<"Enter data:";
    cin>>ptr->data;
    pervious=head;
    current=head->link;
    while(current!=NULL){
        pervious=current;
        current=current->link;
    }
    pervious -> link = ptr;
    ptr -> link = current;
    cout << "add success" << endl;
}
void del(){
    if (head -> link != NULL)
    {
        current = head -> link;
        pervious = current;
        current = current -> link;
        head -> link = current;
        delete pervious;
    }
}
void show(){
    int counter = 1;
    pervious = head;
    current = head -> link;
    while(current != NULL)
    {
        pervious = current;
        current = current -> link;
        cout << counter++ << ":" << pervious -> data << endl;
    }
}




int main(void){
    head = new queue;
    head -> link = NULL;
    while(1){
        int i;
        cout<<"add[1]\n"<<"del[2]\n"<<"show[3]\n"<<"exit[4]"<<endl;
        cin >> i;
        if(i==4){
            cout<<"end";
            break;
        }
        switch(i){
        case 1:
            add();
            break;
        case 2:
            del();
            break;
        case 3:
            show();
            break;
        }

    }
}
































