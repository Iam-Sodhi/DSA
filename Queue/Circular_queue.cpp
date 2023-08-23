#include <iostream>
using namespace std;
//*****we use it as it helps to use space more efficiently
struct circular_queue
{
    int size;
    int f;
    int b;
    int *arr;

public:
    circular_queue(int s)
    {
        size = s;
        f = b = 0; // *****here f and b is not equal to =1
        arr = new int[size];
    }
    bool isfull()
    {
        if ((b + 1) % size == f) //****NOTE: The index at f  should always be empty
        {
            return true;
        }
        return false;
    }
    bool isempty()
    {if(b == f)
        {
            return true;
        }
        return false;
    }
    void enqueue(int n)
    {
        if ((b + 1) % size == f)
        {
            cout << "Queue overflow"<<endl;
            return;
        }
        b = (b + 1) % size; // this is called circular increment e.g. when b=3 and size of queue is 4 then after index 3(b) it will come to 0 index rather than 4
        arr[b] = n;
    }
    int dequeue()
    {
        if (isempty())
        {
            cout << "Queue underflow"<<endl;
            return -1;
        }
        f = (f + 1) % size;
        return arr[f];
    }
};

int main()
{   
     circular_queue q(4);
      q.enqueue(1);
      q.enqueue(2);
      q.enqueue(3);
      //*****NOte as f has to empty in circular queue only size-1 indixes should be filled*****
      q.enqueue(4);  // that's why now overflow will be there
      cout<<q.isfull()<<endl;
      cout<<q.dequeue()<<endl;
      cout<<q.isfull()<<endl;
      cout<<q.dequeue()<<endl;
      cout<<q.dequeue()<<endl;
      cout<<q.isempty()<<endl;

    return 0;
}