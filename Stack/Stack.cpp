#include <iostream>
using namespace std;
class stack
{
    int top;
    int size;
    int *arr;

public:
    stack(int n)
    {
        top = -1;
        size = n;
        arr = new int[n];
    }
    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            int res = arr[top];
            top--;
            return res;
        }
    }

    
    int Top()
    {
        if (top == -1)
        {
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    stack sp(5);
    sp.push(2);
    sp.push(6);
    sp.push(9);
    sp.push(7);
    // cout<<sp.Top()<<endl;
    sp.push(8);
    sp.push(10); // it will not be stored in it as overflow will occur
    cout << sp.pop();

    return 0;
}