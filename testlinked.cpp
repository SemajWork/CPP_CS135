#include <iostream>
using namespace std;

class Node {
public:
    int Value;
    Node* Next;
};
void printList(Node* n) {
    while (n!=NULL) {
        cout << n->Value << endl;
        n = n->Next;
    }
}

void insertAtTheFront(Node**head,int newvalue){
    Node*newNode = new Node();
    newNode->Value=newvalue;
    newNode->Next=*head;
    *head=newNode;
}

void insertAtEnd(Node**head,int newvalue){
    Node*newNode= new Node();
    newNode->Value=newvalue;
    newNode->Next=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node*last=*head;
    while(last->Next!=NULL){
        last=last->Next;
    }
    last->Next=newNode;
}

void insertAfter(Node*previous, int newValue){
    if(previous==NULL){
        cout<<"Empty List";
        return;
    }
    Node*newnode=new Node();
    newnode->Value=newValue;
    newnode->Next=previous->Next;
    previous->Next=newnode;
}

int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->Value = 1;
    head->Next = second;
    second->Value = 2;
    second->Next = third;
    third->Value = 3;
    third->Next = NULL;
    insertAtTheFront(&head,0);
    insertAtEnd(&head,4);
    insertAfter(head,43);
    insertAfter(second,23);
    printList(head);

    system("pause>0");
}