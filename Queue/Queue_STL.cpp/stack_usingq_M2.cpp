#include <iostream>
#include <queue>
using namespace std;
// pop operation is costly
class stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    stack()
    {
        N = 0;
    }
    void push(int x)
    {
        q1.push(x);
        N++;
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        while (q1.size() != 1) // size is inbuil function
        {
            q2.push(q1.front());
            q1.pop();
        }
        // to pop the last element of queue(top for stack)
        q1.pop();
        N--;
        // Now swap the queues
        queue<int> temp = q2;
        q2 = q1;
        q1 = temp;
    }
    int front()
    {
        if (q1.empty())
        {
            return -1;
        }
        while (q1.size() != 1) // size is inbuil function
        {
            q2.push(q1.front());
            q1.pop();
        }
        // to pop the last element of queue(top for stack)
        int val = q1.front();
        //******here again we need to push last element in q1
        q2.push(val);
        q1.pop();
        // Now swap the queues
        queue<int> temp = q2;
        q2 = q1;
        q1 = temp;
        return val;
    }
    int size(){
        return N;
    }
};
int main()
{  stack s;
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   cout<<s.front()<<endl;
   s.pop();
   cout<<endl<<s.size()<<endl<<endl;
   cout<<s.front()<<endl;
   s.pop();
   cout<<s.front()<<endl;
   s.pop();
   cout<<s.front()<<endl;
   s.pop();
   cout<<s.front()<<endl;
   s.pop();
   cout<<s.size()<<endl;
    return 0;
}