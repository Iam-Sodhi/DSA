#include <iostream>
#include <stack>
using namespace std;
bool check_redunt_paranthesis(string s)
{
    stack<char> st;
    for (int i = 0; s.length(); i++)
    {
        if (s[i] == '*' || s[i] == '-' || s[i] == '/' || s[i] == '*')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                return true;
            }

            while (st.top()=='*'||st.top()=='-'||st.top()=='/'||st.top()=='*')
            {
                st.pop();
            }
            st.pop();  // to remove '('
        }  
    }
    return false;
}
int main()
{
    string s="((a+b))";
      cout<<check_redunt_paranthesis(s);
    return 0;
}