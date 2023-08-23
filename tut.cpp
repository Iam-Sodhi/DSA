#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool know(vector<vector<int>> &M, int n, int a, int b)
{
    if (M[a][b] == 1)
        return true;
    return false;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n + 1, vector<int>(n + 1, 0));
        int p, q;
        for (int i = 0; i < m; i++)
        {
            cin >> p >> q;
            M[p][q] = 1;
        }

        stack<int> s;
        // 1.Push all the members into the stack *** index starting from 0 (0 as the first member)
        for (int i = 1; i <= n; i++)
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
            else
            { // b knows a  //*****if (know(M, n, b, a))  ->don't use it can give segmentation error
              // as it is possible that even b does not know a but we want to push it t
                s.push(a);
            }
        }
        // 3.Now this one element left will be the potential candidate. We will verify it.

        int potCandidate = s.top();
        bool flag = true;
        // checking row
        for (int i = 1; i <= n; i++) // all row elements should be 0
        {
            if (M[potCandidate][i] != 0)
            {
                cout << "dead" << endl;
                flag = false;
                break;
            }
        }
        // checking column
        if (flag)
        {
            for (int i = 1; i <= n; i++)
            {
                if (potCandidate != i)
                {
                    if (M[i][potCandidate] == 0)
                    {
                        cout << "dead" << endl;
                        flag = false;
                        break;
                    }
                }
            }
        }

        if (flag)
            {cout << "alive"
                 << " " << potCandidate << endl;}
    }
    return 0;
}
