#include <iostream>
using namespace std;
// print a;; possible words from phone digits
string ph_words[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void word_phDigits(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string code = ph_words[ch - '0'];
    string res = s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        word_phDigits(res, ans + code[i]);
    }
}
int main()
{
    word_phDigits("23", "");
    return 0;
}