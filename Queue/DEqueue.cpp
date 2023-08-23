#include <iostream>
#include<deque>
using namespace std;
// we can also use STL for it <deque> and do functions like push_front, push_back, pop_front , size etc in it directly
class DEqueue
{
    int f;
    int b;
    int size;
    int *arr;
  
public:
    DEqueue(int s)
    {
        size = s;
        f = b = -1;
        arr = new int[s];
    }
    void enqueue_F(int x)
    {
        if ((f == -1))
        {
            cout << "Queue is full from front side" << endl;
            return;
        }
        arr[f] = x;
        f--;
    }
    void enqueue_B(int x)
    {
        if (b == size - 1)
        {
            cout << "Queue is full on rare side" << endl;
            return;
        }
        b++;
        arr[b] = x;
    }
    int dequeue_F()
    {
        if (f == b)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        f++;
        return arr[f];
    }
    int dequeue_B()
    {
        if (f == b)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int val = arr[b];
        b--;
        return val;
    }
    bool empty()
    {
        if (f == b)
        {
            return true;
        }
        return false;
    }
};
int main()
{  //deque<int> q;
    // q.push_back(1);
    DEqueue q(5);
    q.enqueue_B(1);
    q.enqueue_B(2);
    q.enqueue_B(3);
    q.enqueue_B(4);
   
    cout<<q.dequeue_B()<<endl;
   // q.enqueue_F(5); 
    cout<<q.dequeue_F()<<endl;
    q.enqueue_F(5);
    cout<<q.dequeue_F()<<endl;
    return 0;
}