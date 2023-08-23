#include <iostream>
#include <stack>
using namespace std;
bool isMatching(string s)
{
    stack<char> sp;
    bool ans = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            sp.push(s[i]);
        }
        else if (!sp.empty() && s[i] == ')')
        {
            if (sp.top() == '(')
            {
                sp.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (!sp.empty() && s[i] == '}')
        {
            if (sp.top() == '}')
            {
                sp.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (!sp.empty() && s[i] == ']')
        {
            if (sp.top() == '[')
            {
                sp.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (!sp.empty())
    {
        return  false;
    }

    return ans;
}
int main()
{
    string s = "a+b*(b/c{d}";
    if (isMatching(s))
    if (isMatching(s))
    {
        cout << "The paranthesis are matching" << endl;
    }
    else
    {
        cout << "The paranthesis are not matching" << endl;
    }

    return 0;
}