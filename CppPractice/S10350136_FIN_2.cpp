#include<iostream>
using namespace std;
struct stack{
    int data;
    stack *link;
};
stack *ptr,*head,*current,*pervious;
void add(){
    ptr = new stack;
    cout << "Enter data:";
    cin >> ptr -> data;
    current = head -> link;
    head -> link = ptr;
    ptr -> link = current;
}
void del(){
    current = head -> link;
    pervious = current;
    current = current -> link;
    head -> link = current;
    int del=pervious->data;
    delete pervious;
}

void show(){
int counter = 1;
    pervious = head;
    current = head -> link;
    while(current != NULL)
    {
        pervious= current;
        current = current -> link;
        cout << counter++ << ":" << pervious -> data << endl;
    }
}
int main(void){
    head = new stack;
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