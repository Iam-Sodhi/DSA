#include <iostream>
using namespace std;
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
void Insertion_tail(node *&head, int n)
{
    node *ptr = new node(n);
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    node *pt = head;
    while (pt->next != NULL)
    {
        pt = pt->next;
    }
    pt->next = ptr;
}
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
node *reverse_k_nodes(node *&head, int k)
{
    node *prev = NULL;
    node *curr = head;
    node *nextptr;
    int count = 0;
    while (curr !=NULL && count < k)   // firstly we have reversed the k nodes
    {
        nextptr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextptr;
        count++;                           // 1 2 3 4 5 6
    }
    // here next is pointing at k+1 node   // 2 1 4 3 6 5
     if (nextptr!=NULL)
     {
         head->next =reverse_k_nodes(nextptr,k);    // '1' is head
     }
    return prev;
}

int main()
{   node *head=NULL;
   Insertion_tail(head,1);
   Insertion_tail(head,2);
   Insertion_tail(head,3);
   Insertion_tail(head,4);
   Insertion_tail(head,5);
   Insertion_tail(head,6);
   display(head);
   node *newhead=reverse_k_nodes(head,3);
   display(newhead);

    return 0;
}
