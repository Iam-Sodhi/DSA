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
int length(node *head)
{
    int len = 1;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
void intersect_twolists(node *&head1, node *&head2, int position)
{
    node *temp1 = head1;
    int pos = 1;
    while (pos < position)
    {
        temp1 = temp1->next;
        pos++;
    } // temp1 points at the node where we want to intersect them
    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    } // temp2 points at its last element

    temp2->next = temp1;
}
int intersection_pt(node *head1, node *head2)
{
    node *ptr1; // should pt at head of larger list
    node *ptr2;
    int d = 0; // diff b/w size of two lists
    int l1 = length(head1);
    int l2 = length(head2);
    if (l1 > l2)
    {
        ptr1 = head1;
        ptr2 = head2;
        d = l1 - l2;
    }
    else
    {
        ptr1 = head2;
        ptr2 = head1;
        d = l2 - l1;
    }
    while (d)
    {
        if (ptr1 == NULL)
        {
            return -1;
        }

        ptr1 = ptr1->next;
        d--;
    } // point at (d+1) position
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        Insertion_tail(head1, arr[i]);
    }
    Insertion_tail(head2, 8);
    Insertion_tail(head2, 9);
    intersect_twolists(head1, head2, 4); // intersect them at position 3
    display(head1);
    display(head2);
    cout << intersection_pt(head1, head2);

    return 0;
}
