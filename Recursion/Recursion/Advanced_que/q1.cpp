#include <iostream>
using namespace std;
//Print all permutations( not substrings) of a string
void permutations(string s , string ans){
    if (s.length()==0)
    {cout<<ans<<endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch= s[i];
        string rest=  s.substr(0,i) + s.substr(i+1);
        permutations(rest,ans+ch);
    }
    
}
int main()
{	  permutations("ABC","");
    return 0;
}