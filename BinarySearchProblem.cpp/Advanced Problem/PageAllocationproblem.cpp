#include <iostream>
using namespace std;
// If n - no of pages in n diff books(ascending order) & m - no of students
// All the books have to be divided among m students consecutively.Allocate the pages in such a way that
//*****maximum pages allocated to a student in minimum.*****
bool ispossible(int pages[], int n, int m, int mid)
{
    int studentcount = 1;
    int pagesum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesum + pages[i] <= mid)
        {
            pagesum += pages[i];
        }
        else
        {
            studentcount++;
            if (studentcount > m || pages[i] > mid) // pages[i]>mid can't be as we need distrubute to each student (none can have o)
            {
                return false;
            }
            pagesum = pages[i];
        }
    }

    return true;
}
int main()
{
    int pages[] = {12, 34, 67, 90};
    int m = 2;
    int n = sizeof(pages) / sizeof(pages[0]);
    int end = 0; // end->sum
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        end += pages[i];
    }
    int ans=INT8_MAX;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (ispossible(pages, n, m, mid))
        {
           // ans = min(ans,mid) ;
           ans=mid;
            end = mid - 1;  //As minimum is needed
        }
        else
        {
            start = mid + 1;
        }
    }
  cout<<ans;
    return 0;
}