// Inserting the node at specific index
// inserting node at the nth position in the list(linked list)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
}; 

Node* insert(Node* head,int data,int position)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = nullptr;

    if (position ==1)
    {
        temp1->next = head;
        head = temp1;
        return head;
    }
    Node* temp2 = head;
    for (int i = 0; i<position-2;i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    return head;
}

void print (Node* head)
{
    while (head!=nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    Node* head = nullptr;
    int i,n,x,p;
    cout<<"Enter the number of elements of the list : \n";
    cin>>n;
    for (i=0;i<n;i++)
    {
        cout<<"first enter the number then enter the position index to which you want to insert in the list: \n";
        cin>>x;
        cin>>p;
        head = insert(head,x,p);
    }

    print(head);
}