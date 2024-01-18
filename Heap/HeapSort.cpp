#include <iostream>
using namespace std;

void heapify(int a[], int n, int i){
    int largest=i;
  
     int leftChild=2*largest; //in 0 indexing 2i+1 (here 2largest +2)
     int rightChild=2*largest+1; // in 0 indexing 2i+2
     if (leftChild<=n && a[largest]<a[leftChild])
     {
        largest=leftChild;
     }
     
      if (rightChild<=n && a[largest]<a[rightChild]) //here not else if so that be compared with both the childs
     {
        largest=rightChild;
     }
      if (largest!=i)
      {
        swap(a[largest],a[i]);
        heapify(a,n,largest);
      }
   
}
void heapsort(int a[], int size) //here size is tha last index initially
{
    while (size > 1)
    {
        // As root is max(maxHeap) , swap a[root]=a[last];
        swap(a[1], a[size]);
        size--;
        // now putting the root node at its correct position
        heapify(a, size, 1);
    }
}
int main()
{ int arr[]{-1,54,53,55,52,50}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    //As elements from n/2+1 to nth index in 1 indexing are leaf nodes, hence no need to send them in heapify fundtion
    int size=n-1;//******important last element at n-1 index
    for (int i = n/2; i >=1; i--)
    {
      heapify(arr, size,i);  //it has time complexibitly O(n)
    }
   cout<<"Printing the array(maxHeap): "<<endl;
   for (int i = 1; i <=size; i++)
   {
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   heapsort(arr,size);
    cout << "Printing the sorted array: " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}