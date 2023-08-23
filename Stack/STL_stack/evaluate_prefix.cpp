#include <iostream>
#include<math.h>
#include<stack>
//we are assuming single integer values
using namespace std;
// in postfix we start from beginning & that's the difference b/w prefix and its evaluation
int evaluate_prefix(string s){
    stack<int> sp;
    int op1,op2;
    for (int i = s.length()-1; i >=0; i--)
    {
        if (s[i]>='0'&& s[i]<='9')
        {
            sp.push(s[i]-'0');
        }
        else
        {   op1=sp.top();
            sp.pop();
            op2=sp.top();
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
{	cout<<evaluate_prefix("-+7*45+20");
    return 0;
}