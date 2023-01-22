#include<iostream>
using namespace std;

void insert();
void del();
void show();

struct stack{
    int data;
    stack *link;
};
stack *head,*current,*previous,*ptr;

int main(void)
{
    char select;
    head = new stack;
    head -> link = NULL;
    cout << "[i]: insert" << endl << "[d]: delete" << endl << "[s]: show" << endl << "[q]: quit" << endl;
    while(1)
    {
        cout << "Select a order: ";
        cin >> select;
        switch(select){
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
            exit(1);
        default:
            cout << "wrong order";
        }

    }
}
void insert()
{
    ptr = new stack;
    cout << "Please enter data: ";
    cin >> ptr -> data;
    current = head -> link;
    head -> link = ptr;
    ptr -> link = current;
    cout << "Insert success" << endl;
}

void del()
{
    current = head -> link;
    previous = current;
    current = current -> link;
    head -> link = current;
    int del=previous->data;
    delete previous;
    cout<<del<<" deleted"<<endl;
}

void show()
{
    int counter = 1;
    previous = head;
    current = head -> link;
    while(current != NULL)
    {
        previous= current;
        current = current -> link;
        cout << counter++ << ": " << previous -> data << endl;
    }
}