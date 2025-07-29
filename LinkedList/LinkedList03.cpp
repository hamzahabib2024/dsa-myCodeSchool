// in this programm we will delete a node at speceific position
# include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head;

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
void print()
{
    Node* temp = head;
    while (temp!= nullptr)
    {
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
void Delete(int n)
{
    Node* temp1 = head;
    if (n==1)
    {
        head = temp1->next; //now head points to the second node
        delete temp1;
        return;
    }

    int i;

    for(i = 0; i<n-2; i++)
    {
        temp1 = temp1->next;// here temp1 points to the (n-1)th positon on the linked list
    }
    Node* temp2 = temp1->next; //temp2 points to the nth node

    if (temp2->next ==nullptr)
    return;

    temp1->next = temp2->next; //temp2->next means (n+1)th node
    delete temp2;
}

int main()
{
    head = nullptr;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);

    print();
    
    int pos;
    cout<<"enter the position of the node to be deleted: " ;
    cin >> pos ;

    Delete(pos);
    print();

}