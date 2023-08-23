#include <bits/stdc++.h>
using namespace std;
//*****Imp Problem******
//Given a string s, find the longest palindromic subsequence's length in s.
//Input: s = "bbbab"
//Output: 4
//Explanation: One possible longest palindromic subsequence is "bbbb"


//this question can be solved using last question approach , we just need to make another 
//string to store the given string. and reverse the given string
int solveSpace(string a, string b)
{
    int n = a.length();
    int m = b.length();
    vector<int> curr(m+1,0);
    vector<int> next(m+1,0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
                ans = 1 + next [j + 1];

            else
            {
                ans = max(next[j], curr[j + 1]);
            }
            curr[j] = ans;
        }
        next=curr;
    }
    return next[0];
}
int longestPalindrome(string s) {
        string t= s;
        reverse(s.begin(), s.end());
       return solveSpace(s,t);

    }
int main()
{	
    return 0;
}