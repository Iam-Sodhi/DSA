#include <iostream>
#include <stack>
using namespace std;
// Using two stacks --> Dequeue operation is costly
class queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void push_(int x)
    {
        s1.push(x); // time complexibility O(1)
    }
    int pop_() // time complexibility O(n)
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (s2.empty())
        {

            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }
};
int main()
{
    queue q;
    q.push_(1);
    q.push_(2);
    q.push_(3);
    q.push_(4);
    cout << q.pop_() << endl;
    q.push_(5);
    cout << q.pop_() << endl;
    cout << q.pop_() << endl;
    cout << q.pop_() << endl;
    cout << q.pop_() << endl;
    cout << q.pop_() << endl;
    return 0;
}