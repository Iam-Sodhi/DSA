#include <iostream>
using namespace std;
// give all sustrings with their ASCII value
void sub(string s, string ans){
    if (s.length()==0)
    {  cout<<ans<<endl;
    return;
    }
    char ch=s[0];
    int n=ch;
    string res=s.substr(1);
    sub(res,ans);
    sub(res,ans+ch);
    sub(res,ans+to_string(n));

}
int main()
{	sub("AB","");
    return 0;
}