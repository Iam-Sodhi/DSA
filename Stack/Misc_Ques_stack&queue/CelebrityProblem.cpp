#include <bits/stdc++.h>
using namespace std;
// A celebrity is a person who is known to all but does not know anyone at a party.
//  If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j
//  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Follow 0 based indexing.

//********We will not check diagonal elements as it is pointless*******
// *******Celebrity-> row -> all 0's*******
// *******Celebrity -> column -> all 1's except diagonal element*******
// we can use the two loops to find above but it will be O(n2) hence we will use stack to optimize it to O(n).
bool know(vector<vector<int>> &M, int n, int a, int b)
{
    if (M[a][b] == 1)
        return true;
    return false;
}
int celebrity(vector<vector<int>> &M, int n)
{
     stack<int> s;
    // 1.Push all the members into the stack *** index starting from 0 (0 as the first member)
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    // 2.Now until s.size()>1 , pop the first two elements and apply following conditions
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (know(M, n, a, b))
        { // a knows b (hence a can't be celebrity)
            s.push(b);
        }
        else { // b knows a  //*****if (know(M, n, b, a))  ->don't use it can give segmentation error
                                                //as it is possible that even b does not know a but we want to push it t
                     s.push(a);
                 }
    }
    // 3.Now this one element left will be the potential candidate. We will verify it.

    int potCandidate = s.top();
    // checking row
    for (int i = 0; i < n; i++) // all row elements should be 0
    {
        if (M[potCandidate][i] != 0)
            return -1;
    }
    // checking column
    for (int i = 0; i < n; i++)
    {
        if (potCandidate != i)
        {
            if (M[i][potCandidate] == 0)
               return -1;
        }
    }
    
        return potCandidate;
}
int main()
{
    return 0;
}