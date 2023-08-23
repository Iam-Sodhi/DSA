#include <iostream>
#include <vector>
using namespace std;
// Given a string , find the length of Longest substring without repeating character
int lenght(string s)
{
    vector<int> a(256, -1);
    int max_len = 0;
    int start = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (a[s[i]] > start)
        {
            start = a[s[i]];
        }
        a[s[i]] = i;
        int len = i - start;
        max_len = max(max_len, len);
    }
    return max_len;
}
int main()
{
    string s = "pwwkew"; // here ans is 3 (wke) or kwe
    cout << lenght(s);
    return 0;
}