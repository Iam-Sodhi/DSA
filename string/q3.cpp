#include <iostream>
#include<string>
#include<string>
//find maximum occuring character in the string;
using namespace std;
int main()
{	string s="asdbdfdsdffgfbnf";
    
    int freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i]=0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]-'a']++;
    }
    int maxf=INT8_MIN;
    char ans;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i]>maxf)
        {
            maxf=freq[i];
            ans='a'+i;

        }
        
    }
    cout<<"The most occuring alphabet is "<<ans<<" which has occured "<<maxf<<" times."<<endl;
    
    return 0;
}