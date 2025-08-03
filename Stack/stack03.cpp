// reverse the string and reverse the linked list using stack

#include <iostream>
#include <cstring>
using namespace std;

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

void Reverse(char C[], int n)
{
    Stack<char> s(101);
    for (int i = 0; i<n; i++)
    {
        s.push(C[i]);
    }

    for (int i = 0; i<n; i++)
    {
        C[i] = s.Top();
        s.pop();
    }
}

int main()
{
    char C[51];
    cout<<"Enter the string : ";
    // gets(C); instead of it we use the following line of code
    cin.getline(C,51);
    int len = strlen(C);

    Reverse(C,len);

    cout<<C;
}