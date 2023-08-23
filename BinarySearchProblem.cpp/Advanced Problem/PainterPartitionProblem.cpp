#include <iostream>
using namespace std;
//*****Painter's Partition Problem******
// n-length of n diff  boards & m- painters available
// A painter paints 1 unit of board in 1 unit of time & each painter will paint consecutive boards.
// Find the minimum time that will be required to paint all the boards
// It is similiar to ******Page Allocation  Problem***** as need mnimum time from maximum
bool ispossible(int boards[], int n, int m, int mid)
{
    int paintercount = 1;
    int boardsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (boardsum + boards[i] <= mid)
        {
            boardsum += boards[i];
        }
        else
        {
            paintercount++;
            if (paintercount > m || boards[i] > mid)
            {
                return false;
            }
            boardsum=boards[i];
        }
    }
    return true;
}
int main()
{
    int boards[] = {10, 20, 30, 40};
    int n = sizeof(boards) / sizeof(boards[0]);
    int m = 2; // no of painters

    int ans = -1;
    int start = 0; // or we can make start = max value of boards[i]
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        end += boards[i];
    }

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (ispossible(boards, n, m, mid))
        {
            ans = mid;
            end = mid - 1; // As we need to find the minimum time
        }
        else
        {
            start = mid + 1;
        }
    }
  cout<<"The minimum time to paint boards: "<<ans<<endl;
    return 0;
}