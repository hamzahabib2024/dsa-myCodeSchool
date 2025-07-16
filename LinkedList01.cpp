#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* insert(Node** head,int data)   // here the **node means the address of the pointer head
                                    // and *head is the address stored in the pointer head
{
    Node* temp = new Node();
    temp->next = nullptr;
    temp->data = data;
    if (*head==nullptr)
    {
        *head = temp;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
    return *head;
}

void print(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}


int main()
{
    Node* head = nullptr; //empty list

    int n,i,x;

    cout<<"enter number of elements that will be present in the linked list"<<endl;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"\nEnter the element ie number: "<<endl;
        cin>>x;
        cout<<"\n"<<x<<endl;
        insert(&head,x);
        print(head);
    }


}