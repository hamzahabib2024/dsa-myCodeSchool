// implementation of the doubly linked list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};




Node* GetNewNode(int data) // this function returns the newly created node that is created in the heap memory
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    temp->prev = nullptr;

    return temp;
}




Node* head = nullptr;




void InsertAtHead(int data)
{
    Node* newNode = GetNewNode(data);

    if(head == nullptr)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}



void InsertAtTail(int data)
{
    Node* newNode = GetNewNode(data);
    
    if(head == nullptr)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}




void Print()
{
    Node* temp = head;
    while(temp!= nullptr)
    {
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}


void ReversePrint()
{
    Node* temp = head;
    while(temp->next!= nullptr)
    {
        temp = temp->next;
    }
    cout<<"reverse: ";
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<"\n";
}




int main()
{
    InsertAtTail(4);
    InsertAtTail(6);
    InsertAtTail(5);

    InsertAtHead(2);

    Print();
    ReversePrint();
}