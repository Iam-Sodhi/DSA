#include <iostream>
using namespace std;
//reverse a string
void reverse(string s){
    if (s.length()==0)
    {
        return;
    }
    string res= s.substr(1);
    reverse(res);
    cout<<s[0];
}
int main()
{	 string s="binod";
     reverse(s);
    return 0;
}