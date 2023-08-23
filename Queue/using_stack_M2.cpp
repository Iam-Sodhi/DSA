#include <iostream>
#include<stack>
using namespace std;
//using funciton call
class queue{
    stack<int> s1;
    public:  void push_(int x){
        s1.push(x);
    }
    int pop_(){
        if (s1.empty())
        {    cout<<"Queue is empty"<<endl;
            return -1;
        }
        int x=s1.top();
        s1.pop();
        if (s1.empty())   // to tackle the case when only one element is present
        {
            return x;
        }
        int item=pop_();  // call recursively
        s1.push(x);
        return item;
        
    }
    bool empty(){
        if (s1.empty())
        {
            return true;
        }
        return false;
    }
};
int main()
{	queue q;
    q.push_(1);
    q.push_(2);
    q.push_(3);
    q.push_(4);
    cout<<q.pop_()<<endl;
    q.push_(5);
    cout<<q.pop_()<<endl;
    cout<<q.pop_()<<endl;
    cout<<q.pop_()<<endl;
    cout<<q.pop_()<<endl;
    cout<<q.pop_()<<endl;
    return 0;
}