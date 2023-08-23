#include <iostream>
#include <queue>
using namespace std;
// Given an array , Find the Kth smallest element of the array
// We can either first sort the array, then find the kth  largest element a(has time complexity O(nlogn))
//****We are gonna use Max heap method here **** 
//******to find the smallest Kth element of the array, use the max heap method
//******to find the kth largest element, use the min heap method
int KthSmallestElement(int a[], int k, int n)
{  //  has space complexity O()
    // First put the first K elements in the max heap
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(a[i]);
    }
    // Now the compare the top of max heap with the rest of the elements, if pq.top()> element then pop the top & push the element in the pq
    for (int i = k; i < n; i++)
    {
        if (pq.top() > a[i])
        {
            pq.pop();
            pq.push(a[i]);
        }
    }
  // Now the element at the top is the Kth Smallest element
  return pq.top();
}
int main()
{
    int a[] = {1, 6, 8, 10, 12, 3};
    int k = 3;
    int n = sizeof(a) / sizeof(a[0]);
    int ans=KthSmallestElement(a,k,n);
    cout<<"The Kth Smallest Element in the Given array is "<<ans<<endl;
    return 0;
}