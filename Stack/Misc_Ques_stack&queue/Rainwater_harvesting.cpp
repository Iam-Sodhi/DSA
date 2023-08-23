#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// calculate the water which blocks may hold
int rainwater_harv(vector<int> a)
{
    int n = a.size();
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && (a[st.top()] < a[i]))
        {
            int curr = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            int diff = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[curr]) * diff;
        }
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rainwater_harv(a);
    return 0;
}