#include <iostream>
using namespace std;
class Queue
{
    int size;
    int f; // front
    int b; // back
    int *arr;

public:
    Queue(int s)
    {
        size = s;
        f = b = -1;
        arr = new int[s];
    }
    void enqueue(int n)
    {
        if (b == size - 1)
        {
            printf("Stack Overflow");
            return;
        }
        b++;
        arr[b] = n;
    }
    int dequeue()
    {
        if (f == b)
        {
            cout << "No Element is present";
            return -1;
        }
        f++;
        return arr[f];
    }
    bool isfull()
    {
        if (b == size - 1)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (f == b)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Queue q(4);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.isfull() << endl;
    ;

    q.enqueue(5);
    cout << endl
         << q.dequeue() << endl;
    return 0;
}