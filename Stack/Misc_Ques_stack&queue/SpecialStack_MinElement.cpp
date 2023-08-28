#include <bits/stdc++.h>
using namespace std;
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// Implement the MinStack class:
// MinStack() initializes the stack object.
// void push(long long val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// long long top() gets the top element of the stack.
// long long getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.


// we will use two formulas here:  to get prev min using current mini
//push -> 2* current -mini
//pop-> 2* mini -current     or 2*x - (2*x- prevmini) = prevMini
class MinStack {
public:
    stack<long long> s;
    long long mini=INT_MAX;
    MinStack() {
    }
    
    void push(long long val) {
        if(s.empty()){
            s.push(val);
            mini = val;
        }
        else{
        if(val<mini){
            long long t= 2*val- mini;
            mini=val;
            s.push(t);
        }
        else{
            s.push(val);
        }
         }
    }
    
    void pop() {
        if(!s.empty()){
           
           long long curr=s.top();
            s.pop();
           if(curr<mini){
            long long prevMini=mini;
            long long val=2*mini-curr;
           mini=val;
           }
        }

    }
    
    long long top() {
        if(s.empty()){
            return -1;
        }
        else{
            long long curr=s.top();
            if(curr<mini){
                return mini;
            }
            else{
                return curr;
            }
        }
    }
    
    long long getMin() {
        if(s.empty()) return -1;
        return mini;
    }
};
long long main()
{	
    return 0;
}