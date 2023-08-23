#include <iostream>
#include<math.h>
#include<stack>
using namespace std;

int evaluate_postfix(string s){
    stack<int> sp;
    int op1,op2;
    for (int i = 0; i <s.length(); i++)
    {
        if (s[i]>='0'&& s[i]<='9')
        {
            sp.push(s[i]-'0');
        }
        else
        {   op2=sp.top(); // here op2 will be here instead of op1
            sp.pop();
            op1=sp.top();
            sp.pop();
            switch (s[i])
            {
            case '+':
                sp.push(op1+op2);
                break;
            case '-':
                sp.push(op1-op2);
                break;
            case '*':
                sp.push(op1*op2);
                break;
            case '/':
                sp.push(op1/op2);
                break;
            case '^':
                sp.push(pow(op1,op2));
                break;
            
            default:
                break;
            }
        }
        
    }
    return sp.top();
    
}
int main()
{	cout<<evaluate_postfix("46+2/5*7+");
    return 0;
}