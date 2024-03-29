#include <iostream>
#include<stack>
using namespace std;
int prec(char a){
    if (a=='^')
    {
        return 3;
    }
    else if (a=='*'||a=='/')
    {
        return 2;
    }
    else if (a=='+'||a=='-')
    {
            return 1;
    }
    else
    {
        return -1;
    }
    
    
}
string infixtopostfix(string s){
       stack<char> sp;
       string res;
       for (int i = 0; i < s.length(); i++)
       {
        if (s[i]>='a'&&s[i]<='z'||(s[i]>='A'&&s[i]<='Z'))
        {
            res+=s[i];
        }
        else if (s[i]=='(')
        {
           sp.push(s[i]);
        }
        else if (s[i]==')')
        {
           
            while (!sp.empty()&& sp.top()!='(')
            {
                 res+=sp.top();
            sp.pop();
            }
            if (sp.top()=='(') // to remove it
            {
                sp.pop();
            }
            
        }
        else
        {
            while (!sp.empty()&& prec(s[i])<=prec(sp.top()))
            {
                res+=sp.top();
                sp.pop();
            }
            sp.push(s[i]);
        }
        
        
        
       }
       while (!sp.empty())
       {
        res+=sp.top();
        sp.pop();
       }
       
     return res;  
}
int main()
{	cout<<infixtopostfix("(a-b/c)*(a/k-l)");
    return 0;
}