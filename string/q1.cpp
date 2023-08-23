#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
//change uppercase to lowercase and vice-versa in the string
string convert_upr(string s){
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i]>='a'&& s[i]<='z')
    {
      s[i]=s[i]-32;
    }
  
    
  }
  return s;
    
}
string convert_lwr(string s){
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i]>='A'&& s[i]<='Z')
    {
      s[i]=s[i]+32;
    }
  
    
  }
  return s;
    
}
int main()
{	string s="abcdefghij";
    cout<<convert_upr(s)<<endl;;
   
   cout<< convert_lwr(s)<<endl;
   // we can also use inbuilt function
   transform(s.begin(),s.end(),s.begin(),::toupper); // 3rd means from where to start
   cout<<s<<endl;
   transform(s.begin(),s.end(),s.begin(),::tolower);
   cout<<s;
    return 0;
}