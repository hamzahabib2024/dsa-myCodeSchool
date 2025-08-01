//implementation of stack using linked list

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(): data(0),next(nullptr){}
    Node(int x): data(x),next(nullptr){}
};

Node* Push(Node* head, int x)
{
    Node* newNode = new Node(x);
    if (head == nullptr)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

Node* Pop(Node* head)
{
    if (head == nullptr)
    {
        cout<<"Error: stack is empty";
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    
    return head;
}

void Print(Node* head)
{
    while (head!= nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int Top(Node* head)
{
    return head->data;
}

int main()
{
    Node* head = nullptr;

    head = Push(head, 2);
    head = Push(head, 4);
    head = Push(head, 6);
    head = Push(head, 5); 
    Print(head);

    head = Pop(head); 
    Print(head);

    int top = Top(head);
    cout<<"The top element of the list is : "<<top;
}
