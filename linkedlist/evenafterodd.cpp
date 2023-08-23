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
void evenafterodd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenstart=even;
    while (odd->next!=NULL&&even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    // here if there are odd positions then even->next=NULL by above code
    // if even no of positions, then
    if (odd->next!=NULL)
    {
        even->next=NULL;
    }
    odd->next=evenstart;
}
int main()
{	
       node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        Insertion_tail(head, arr[i]);
    }
    evenafterodd(head);
    display(head);
    return 0;
}