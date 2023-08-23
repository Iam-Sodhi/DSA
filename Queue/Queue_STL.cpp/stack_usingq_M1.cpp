#include <iostream>
#include<queue>
using namespace std;
//push method is costly 
class stack{
    int N; // for size
    queue<int> q1;
    queue<int> q2;
    public:
    stack(){
        N=0;
    }
    void push(int x){
        q2.push(x);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());  // front in queue but in stacks we use top
            q1.pop();

        }

        //swqping two queues
        queue<int> temp=q2;
        q2=q1;
        q1=temp;
        
    }
    void pop(){
        if (q1.empty())
        {  cout<<"Stack is empty"<<endl;
           return;
           
        }
        
        q1.pop();
        N--;
    }
    int front(){
        if (q1.empty())
        {  
           return -1;
           
        }
        return q1.front();
    }
    int size(){
        return N;
    }
    
};
int main()
{	stack s;
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