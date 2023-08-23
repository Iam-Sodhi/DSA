#include <iostream>
using namespace std;
// It is a complete binary tree ( every level should be completely filled except the last level & nodes always added feom the left)
//  It can be max heap and min heap
class heap
{
public:
    int size;
    int a[100];
    heap()
    {
        size = 0;
        a[0] = -1; // it is 1st index heap (means at 0th index just put any garbage value)
    }
    
    // For max heap
    void insertion(int n)
    {
        size++;
        a[size] = n;
        // in 1 index parent of i index = i/2 & in 0 indexing = (i-1)/2
        int i = size;
        while (i > 1)
        {
            int parent = i / 2;
            if (a[parent] < a[i])
            {
                swap(a[parent], a[i]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deletion()
    {
        if (size == 0)
        {
            cout << "Nothing to be deleted";
            return;
        }

        // swap first node(to be deleted) with the last node
        a[1] = a[size];
        // deleting the node
        size--;
        // prpagate the root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftChild = 2 * i;      // in 0 indexing it is 2i+1
            int rightChild = 2 * i + 1; // in 0 indexing it is 2i+2
            if (leftChild <= size && a[i] < a[leftChild])
            {
                swap(a[leftChild], a[i]);
                i = leftChild;
            }

            else if (leftChild <= size && a[i] < a[leftChild])
            {
                swap(a[rightChild], a[i]);
                i = rightChild;
            }
            else
            {
                return;
            }
            
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    heap h;
    h.insertion(50); //insertion and deletion has O(logn) complexibilty
    h.insertion(55);
    h.insertion(53);
    h.insertion(52);
    h.insertion(54);
    h.print();
    h.deletion();
    h.print();
    return 0;
}