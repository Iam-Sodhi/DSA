#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Given array of *****distinct***** integers, return all possible permutations. You can return the answer in any order.
// In method 2, we can use STl
//Both methods will have O(N!) complexity

//M-1
void permute(vector<int> a, int idx, vector<vector<int>> &ans)
{
    if (idx == a.size())
    {
        ans.push_back(a);
    }

    for (int i = idx; i < a.size(); i++)
    {
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
        cin >> i;
    }
    vector<vector<int>> ans;
    // permute(a, 0, ans);  


    // Or we can use STL based on above
    sort(a.begin(), a.end());
    do
    {
        ans.push_back(a);
    } while (next_permutation(a.begin(), a.end())); // next_permutation will give the next greater permutaion till it is possible



    cout << endl;
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