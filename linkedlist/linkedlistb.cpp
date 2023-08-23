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
        return; // to exit the function
    }
    node *pt = head; // here do it otherwise the head will change as we  passed head with address
    while (pt->next != NULL)
    {
        pt = pt->next;
    }
    pt->next = ptr;
    // ptr->next=NULL;   //no need for it as it is already done by our constructor from the class
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
int main()
{
    node *head = NULL;
    Insertion_tail(head, 4);
    Insertion_tail(head, 6);
    Insertion_tail(head, 9);
    Insertion_tail(head, 15);
    display(head);
    Insertion_tail(head,67);
    display(head);
    return 0;
}