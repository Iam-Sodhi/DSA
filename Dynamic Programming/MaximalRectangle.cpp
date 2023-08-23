#include <bits/stdc++.h>
using namespace std;
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// we will solve this question using the largest rectangle in histogram .
// in each row, we will update the heights(self made) array to have new histogram , and find the area wrt to that.

vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    // this is based on indexes
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i]) // as here s.top() can be -1 and arr[-1] is wrong
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i); // as based on index
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> arr, int n) // just the change the loop direction
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    // this is based on indexes
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i]) // as here s.top() can be -1 and arr[-1] is wrong
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i); // as based on index
    }
    return ans;
}
int largestAreaHistogram(vector<int> heights)
{
    int n = heights.size();
    vector<int> next(n);
    next = nextSmallerElement(heights, n);
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int h = heights[i];
        if (next[i] == -1)
            next[i] = n;
        int w = next[i] - prev[i] - 1;
        area = max(area, h * w);
    }
    return area;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);
    int maxRactangle = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
                heights[j]++;
            else //***** make it 0 *****
            {
                heights[j] = 0;
            }
           
        }
         maxRactangle = max(maxRactangle, largestAreaHistogram(heights));
    }
    return maxRactangle;;
}
int main()
{
    return 0;
}