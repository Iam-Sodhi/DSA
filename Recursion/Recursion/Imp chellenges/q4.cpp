#include <iostream>
using namespace std;
// Remove all the duplicates
// bool map[26];

// void remove(string s, int idx, string newString)
// {

//     if (idx == s.length())
//     {
//         return;
//     }
//     char currChar = s[idx];
//     if (map[currChar - 'a'] == true)
//     {
//         remove(s, idx + 1, newString);
//     }
//     else
//     {
//         cout << currChar;
//         map[currChar - 'a'] = true;
//         remove(s, idx + 1, newString);
//     }
// }
string remove(string s){
      if (s.length()==0)
      {
        return"";
      }
      char ch=s[0];
      string ans= remove(s.substr(1));
      if (ch==ans[0])
      {
         return ans;
      }
      return ch+ ans;

}
int main()
{
    string s = "aaaabbbbccdeeee";
    // remove(s, 0, "");

    cout<<remove(s);

    return 0;
}