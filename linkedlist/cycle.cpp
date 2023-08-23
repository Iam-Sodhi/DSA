#include <iostream>
using namespace std;
//*****Floyd's Triangle*****->important question
// Detect cycle, Make cycle and remove cycle in linked list
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
    cout<<endl;
}
bool detect_Cycle(node *head)
{
    node *slow = head;
    node *fast = head; // distance by fast=2*distance by slow
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if (slow == head)
    {
        return true;
    }
    return false;
}
void make_Cycle(node *head, int position)
{
    node *startnode;
    node *temp = head;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == position)
        {
            startnode = temp;
        }

        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}
void delete_cycle(node *head)   //assuming it has cycle in it
{
    node *fast = head;
    node *slow = head;
    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != head);
    // upto here slow and head are at the position where they meet
    fast = head;
    while (slow->next != fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next=NULL;
}

int main()
{
    node *head = NULL;
    Insertion_tail(head, 1);
    Insertion_tail(head, 2);
    Insertion_tail(head, 3);
    Insertion_tail(head, 4);
    Insertion_tail(head, 5);
    Insertion_tail(head, 6);
    // display(head);
    // cout << detect_Cycle(head);
    make_Cycle(head, 4);
//   display(head); // it would n't terminate
  //  delete_cycle(head);
    cout<<detect_Cycle(head);

    return 0;
}
