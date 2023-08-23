#include <bits/stdc++.h>
using namespace std;
//Design a data structure to implement 'N' stacks using a single array of size 'S'. It should  suuport the following operations:
// push(x,n): pushes an element x into the mth stack, returns true if it is pushed , otherwise returns false.
//pop(m): pops an element from the mth stack. Returns -1 if the stack is empty, otherwise returns the popped element.

// ***** to implement it , we need an array to store top element of n stacks, and array of name 'next' which either store the index of  next freeSpot or the index of next element of that stack.
class NStack{
    public:
     int n,s;
      int * arr;
      int * top;
      int * next;
      int freeSpace; //it keeps the track of the next available free space

    NStack(int N,int S){
        n=N;
        s=S;
        arr=new int[s];
        top=new int[n]; // stores the s.top() of n stacks
        next=new int[s];// also have size s

        //top initialize
        for (int i = 0; i < n; i++) 
        {
            top[i]=-1;
        }
        

        for (int i = 0; i < s-1; i++)  //next initialize
        {
            next[i]=i+1;
        }
        next[s-1]=-1; // as last element will not have any empty space after it.
        freeSpace=0;  //initialize freeSpace ( as first freeSpace initially is 0 index)
        
    }
    bool push(int x,int m){
       if(freeSpace==-1){ // means freeSpace is not available
            return false;
       }
       //first find index
       int index=freeSpace;
       arr[index]=x;
       //update the freeSpace
       freeSpace=next[index];

       //update next as now it does not point to freespace but the element ( s.top() ke neeche wala) i.e. top[m-1] or top of mth stack
       next[index]=top[m-1];
       //update top
       top[m-1]=index;
       return true;
    }
    int pop(int m){
        if(top[m-1]==-1){ //means mth stack is empty
            return -1;
        }
        //now just reverse the steps of push function and order
       int index=top[m-1];
       top[m-1]=next[index];
       next[index]=freeSpace;
       int x=arr[index];
       freeSpace=index;
       return x;
    }
};
int main()
{	
    return 0;
}