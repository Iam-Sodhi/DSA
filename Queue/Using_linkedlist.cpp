#include <iostream>
using namespace std;
// Here we don't need to know its size
class node
{
public:
    int data;
    node *next;

    node(int n)
    {
        data = n;
        next = NULL;
    }
};
class queue
{
    node *f;
    node *b;

public:
    queue()
    {
        f  = NULL;
        b = NULL;
    }

    void push(int data) // here we need to insert at the tail (opposite of like stack)
    {
        node *ptr = new node(data);
        if (ptr == NULL) // this is the condition of full queue
        {
            cout << "Queue is full" << endl;
           return;
        }
     
        

            if (f == NULL) // it means when queue is empty
            {
                f = ptr; // we need both of them to increase
                b = ptr;
                return;
            }
            else
            {
                b->next = ptr;
                b = ptr;
            }
        
    }
    int peek()
    {
       
        if (f == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return f->data;
    }
    void pop()
    {
       
        if (f == NULL)
        {
            cout << "Queue is empty" << endl;
            return ;
        }
         node *ptr = f;
        f = f->next;
        free(ptr);
    }
    void display()
    {
        node *ptr = f;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
};
int main()
{   queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    //  cout<<q.peek()<<endl;
    //  q.pop();
    //  cout<<q.peek()<<endl;
    //  q.pop();
    //  cout<<q.peek()<<endl;
    //  q.pop();
    //  cout<<q.peek()<<endl;
    //  q.pop();
    q.display();
    return 0;
}