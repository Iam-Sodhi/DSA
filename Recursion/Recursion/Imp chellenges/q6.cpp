#include <iostream>
using namespace std;
// give all substrings
void substrings(string s,string ans){
    if (s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string res=s.substr(1);
    substrings(res,ans);
    substrings(res,ans+ch);
     
}
int main()
{	substrings("ABC","");
    return 0;
}