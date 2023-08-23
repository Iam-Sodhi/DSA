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
    cout<<endl;
}
//iterative way
node *reverse(node *head)
{
    node *curr=head;
    node *prev=NULL;
    node *nextptr;
    while (curr != NULL)
    {
        nextptr = curr->next; //***** do it inside as curr can be null at end
        curr->next = prev;

        prev = curr;
        curr = nextptr;
    }
    head = prev;
    return head;
}
//recursice way
node *reverse_Recursive(node* &head){
    if (head==NULL|| head->next==NULL)
    {
        return head;
    }
    node *newhead=reverse_Recursive(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return newhead;
    
}
int main()
{
    node *head = NULL;
    Insertion_tail(head, 4);
    Insertion_tail(head, 6);
    Insertion_tail(head, 9);
    Insertion_tail(head, 15);
    display(head);
    // node *newhead = reverse(head);
    // display(newhead);
    node *newhead2 = reverse_Recursive(head);
    display(newhead2);

    return 0;
}