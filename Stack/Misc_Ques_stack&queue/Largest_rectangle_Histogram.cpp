#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// Find the area of Largest rectangle in histogram
// we can find it by finding next and prev smaller element for every element

vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    // this is based on indexes
    for (int i = n- 1; i >= 0; i--)
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

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next(n);
    next = nextSmallerElement(heights, n);
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);
    int area = -1e5;
    for (int i = 0; i < n; i++)
    {
        int h = heights[i];

        // when all elements are equal , then prev[i] & next[i] are equal to -1 , means w=-1+1-1=-1
        if (next[i] == -1)  //actually we have stored -1 in our nextSmallerElement function for this case , with proper condition we can change -1 to n inside the function
        {
            next[i] = n;
        }
        int w = next[i] - prev[i] - 1; //-1 see carefully on paper
        int newArea = h * w;
        area = max(area, newArea);
    }
    return area;
}

//this answer may be wrong
// int largest_rect(vector<int> a)
// {
//     int n = a.size();
//     a.push_back(0);
//     stack<int> st;
//     int maxarea = INT8_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         while (!st.empty() && (a[st.top()] > a[i]))
//         {
//             int h = a[st.top()];
//             st.pop();
//             if (st.empty())
//             {
//                 maxarea = max(maxarea, h * i);
//             }
//             else
//             {
//                 int len = i - st.top() - 1; // -1 because we have popped--> st.pop() above
//                 maxarea = max(maxarea, len * h);
//             }
//         }

//         st.push(i);
//     }
//     return maxarea;
// }
int main()
{
    vector<int> a = {2, 1, 5, 6, 2, 3};

  //  cout << largest_rect(a);
    return 0;
}