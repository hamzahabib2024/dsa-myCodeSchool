//Reverse the linked list using recursion

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = nullptr;



void Reverse(Node* p)
{
    if (p->next== nullptr)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = nullptr;
}




void Insert(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    if(head == nullptr)
    {
        head = temp;
        return;
    }

    Node* temp2 = head;
    while(temp2->next!=nullptr)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;

}




void Print()
{
    Node* temp = head;
    while (temp!= nullptr)
    {
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<"\n";
}


int main()
{
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);

    Print();

    Reverse(head);

    Print();
}