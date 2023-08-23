#include <iostream>
#include <cstring>
using namespace std;
class stack
{
    int top;
    int size;
    char *arr;

public:
    stack(int n)
    {
        top = -1;
        size = n;
        arr = new char[n];
    }
    void push(char val)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    char pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            int res = arr[top];
            top--;
            return res;
        }
    }
    int Top()
    {
        if (top == -1)
        {
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == size - 1;
    }
};
//****Below functions are only for *,/,+,- for other operator you have to update them
int precedence(char a)
{
    if (a == '*' || a == '/')
    {
        return 3;
    }
    else if (a == '+' || a == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperator(char a)
{
    if (a == '/' || a == '*' || a == '+' || a == '-')
    {
        return 1;
    }
    return 0;
}
char *infixtopostfix(char *inf)
{
    stack sp(100);
    char *pfx = new char[strlen(inf) + 1];
    int i = 0; // for infix
    int j = 0; // for postfix
    while (inf[i] != '\0')
    {
        if (!isOperator(inf[i]))
        {
            pfx[j] = inf[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(inf[i]) > precedence(sp.Top()))
            {
                sp.push(inf[i]);
                i++;
            }
            else
            {
                pfx[j] = sp.pop();
                j++;   // here i will be fixed 
            }
            
        }
     
    }
       while (!sp.isEmpty())
        {
            pfx[j] = sp.pop();
            j++;
        }
        pfx[j] = '\0';
        return pfx;
}
int main()
{
    char *infix = "a-b*d+c\0";
    cout << "Its postfix is  " << infixtopostfix(infix);
    return 0;
}