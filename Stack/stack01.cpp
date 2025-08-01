// implementation of stack data structure using arrays

#include <iostream>
using namespace std;

int max_size = 101;
int a[101];
int top = -1;

void Push(int data)
{
    if(top == max_size-1)
    {
        cout<<"stack overflow";
        return;
    }

    a[++top] = data;
}
void Pop ()
{
    if (top ==-1)
    {
        cout<<"Error: stack is empty\n";
        return;
    }
    top -= 1;
}

void Print()
{
    int i = 0;
    while(i<=top)
    {
        if(top == -1)
        {
            cout<<"the stack is empty\n";
            return;
        }
        cout<<a[i]<<" ";
        i++;
    }
    cout<<"\n";
}

int Top()
{
    return a[top];
}

int main()
{
    Push(2); Print();
    Push(4); Print();
    Push(6); Print();
    Push(5); Print();

    Pop(); Print();
    Pop(); Print();

    int top = Top();
    cout<<top;
}