#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// Find the span of the stocks for all the days ( span of today's stock price is the max no of consecutive days starting from today for which the price of stocks was less than or equals to todays price)
vector<int> span_stocks(vector<int> a)
{
    stack<pair<int, int>> st;
    vector<int> ans;
    for (auto price : a)
    {
        int days = 1;
        while (!st.empty() && st.top().first < price)
        {
            days += st.top().second;
            st.pop();
        }
        st.push(make_pair(price, days));
        ans.push_back(days);
    }
    return ans;
}
int main()
{
    vector<int> a = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = span_stocks(a);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}