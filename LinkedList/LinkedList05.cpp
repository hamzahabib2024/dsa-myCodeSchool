//print the linked list using recursion and also the reverse of the linked list
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void Print(Node* p)
{
    if(p == nullptr) //exit condition
    return;

    cout<<p->data<<" "; // print the value in the node
    Print(p->next); //Recursive call
}
void PrintReverse(Node* p)
{
    if(p == nullptr) //exit condition
    return;

    Print(p->next); //Recursive call

    cout<<p->data<<" "; // print the value in the node
}

Node* Insert(Node* head, int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
        return head;
    }

    Node* temp2 = head;
    while(temp2->next!= nullptr)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;

    return head;
}

int main()
{
    Node* head = nullptr;

    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,5);

    Print(head);
    cout<<"\n";
    PrintReverse(head);

}