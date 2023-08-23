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
    int peak(int pos)
    {
        if (top - pos + 1 < 0)
        {
            return -1;
        }
        else
        {
            return arr[top - pos + 1];
        }
    }
    int stack_Top()
    {
        return arr[top];
    }
    int stack_Bottom()
    {
        return arr[0];
    }
};

int main()
{
    stack sp(6);

    sp.push(3);
    sp.push(6);
    sp.push(9);
    sp.push(11);
    sp.push(2);
    sp.push(4);
    // sp.push(4); // -->stack overflow
    int pos = 4;
    cout << "The element at position " << pos << " is " << sp.peak(pos) << endl;
    cout << sp.stack_Top() << endl;
    cout << sp.stack_Bottom() << endl;
    return 0;
}
