// reverse the linked list using stack

#include <iostream>
#include <cstring>
using namespace std;


struct Node
{
    int data;
    Node* next;
    Node(): data(0),next(nullptr){}
    Node(int x): data(x),next(nullptr){}
};

Node* Insert(Node* head, int x)
{
    Node* temp = new Node(x);
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

void Print(Node* head)
{
    while(head!= NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

template<typename T>
class Stack
{
private:
    int capacity;
    int top;
    // T* A; // it can be written as (T A[];)
public:
    T* A; // it can be written as (T A[];)
    Stack(int capacity)
    {   this->capacity = capacity;
        top = -1;
        A = new T[capacity];
    }
    ~Stack()
    {
        delete[] A;
    }
    void push(T x)
    {
        A[++top] = x;
    }
    void pop()
    {
        top = top - 1;
    }
    void Print()
    {
        for (int i = 0 ; i<=top; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<"\n";
    }
    T Top()
    {
        return A[top];
    }
    bool IsEmpty()
    {
        return (top == -1);
    }
    bool IsFull()
    {
        return (top == capacity-1);
    }
};

Node* Reverse(Node* head)
{
    if (head == nullptr)
    return head;

    Stack<Node*> s(101);

    Node* temp = head;
    while (temp != nullptr)
    {
        s.push(temp);
        temp = temp->next;
    }
    temp = s.Top();
    head = temp;
    s.pop();
    while(!s.IsEmpty())
    {
        temp->next = s.Top();
        s.pop();
        temp = temp->next;
    }
    temp->next = nullptr;
    
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

    head = Reverse(head);

    Print(head);


}