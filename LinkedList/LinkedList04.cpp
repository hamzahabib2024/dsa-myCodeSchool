// Reverse the linked list through iteration 
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


Node* Reverse(Node* head)
{
    Node* current,*prev,*next;
    current = head;
    prev = nullptr;
    while(current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;

}


Node* Insert(Node* head,int data)   
{
    Node* temp = new Node();
    temp->next = nullptr;
    temp->data = data;
    if (head==nullptr)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

void print(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main()
{
    Node* head = nullptr;
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,5);

    print(head);
    cout<< "The reverse of the linked list\n";
    head = Reverse(head);
    print(head);
}

