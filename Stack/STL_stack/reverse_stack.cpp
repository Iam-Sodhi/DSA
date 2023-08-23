#include <iostream>
#include<stack>
using namespace std;
void insertatBottom(stack<int> &st, int ele){
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    
    int topele=st.top();
    st.pop();
    insertatBottom(st,ele);
    st.push(topele);
}
void reverse(stack<int> &st){
    if (st.empty())
    {
        return;
    }
    
    int ele=st.top();
    st.pop();
    reverse(st);
    insertatBottom(st,ele);
}
int main()
{	stack<int> sp;
    sp.push(1);
    sp.push(2);
    sp.push(3);
    sp.push(6);
   
    reverse(sp);
    
    while (!sp.empty())
    {
        cout<<sp.top()<<" ";
        sp.pop();
    }
    
    return 0;
}