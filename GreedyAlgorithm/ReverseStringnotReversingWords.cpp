#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
//Given a string S , reverse the string without  reversing its individual words. Words are separated by dots.
//We will use heaps here
int main()
{	 string s ="I.like.this.program.very.much";
      string ans="";

      string temp="";
      for (int i = s.length()-1; i >=0; i--) //start from last
      {
          if (s[i]=='.')
          {  reverse(temp.begin(), temp.end());
              ans+=temp+".";
             temp="";
          }
          else
          {
            temp.push_back(s[i]);
          }
          
      }
      //Now we need to tackle the first word which do not have any '.
      reverse(temp.begin(), temp.end());
              ans+=temp;
      cout<<ans<<endl;
    return 0;
}