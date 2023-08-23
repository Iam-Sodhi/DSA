#include <iostream>
using namespace std;

class stack
{  
    int top;
    int size;
    char* arr;
public:
    stack(int n){
        top=-1;
        size=n;
        arr=new char[n];
    }
   void push( char val){
    if (top==size-1)
    {  cout<<"Stack Overflow"<<endl;
    return;
    }
    else
    {
        top++;
        arr[top]=val;
    }
    
   }
   char pop(){
    if (top==-1)
    {
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else
    {
        int res=arr[top];
        top--;
        return res;
    }
    
   }
   int Top(){
    if (top==-1)
    {
        return -1;
    }
    else
    {
        return arr[top];
    }
    
    
   }
   bool isEmpty(){
    return top==-1;
   }
   bool isFull(){
      return top==size-1;
   }
};
int isMatching(char a, char b){
    if ((a=='('&& b==')')||(a=='{'&&b=='}')||(a=='['&&b==']'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}
 int paranthesisMatch(char* exp){
    stack sp(100);
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        {
            sp.push(exp[i]);
        }
        else if (exp[i]==')'||exp[i]=='}'||exp[i]==']')
        {
            if (sp.isEmpty())
            {
                return 0;
            }
            char popped_char= sp.pop();
            if (!isMatching(popped_char,exp[i]))
            {
                return 0;
            }
            
        }
        
        
    }
    if (sp.isEmpty())   // As at the end of expression, stack should be empty
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
 }

int main()
{
   
  char* exp= "(8)+9*(5}";
  if (paranthesisMatch(exp))   // it will not tell whether the expression is valid or not
  {
    cout<<"The paranthesis is matching"<<endl;
  }
  else
  {
    cout<<"The paranthesis is not matching"<<endl;

  }
  
    

    return 0;
}