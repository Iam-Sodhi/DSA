#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Given a collection of numbers,that might contain duplicates, return all possible unique permutations in any order
void permute(vector<int> a, int idx, vector<vector<int>> &ans)
{
    if (a.size() == idx)
    {
        ans.push_back(a);
    }

    for (int i = idx; i < a.size(); i++)
    {
        if (i != idx && a[i] == a[idx])
        {
            continue;
        }
        swap(a[i], a[idx]);
        permute(a, idx + 1, ans);
        swap(a[i], a[idx]);
    }
}
int main()
{
    int n;
    cin >> n; 
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;   // like 1 1 2
    }
    vector<vector<int>> ans;
    permute(a, 0, ans);
    cout<<endl;
    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}