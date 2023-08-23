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
void Inserttion_atfirst(node* &head, int n){
    node *ptr= new node(n);
    if (head==NULL)
    {
        ptr->next=ptr;
        head=ptr;
        return;
    }
    
    node *pt=head;
    while (pt->next!=head)
    {pt=pt->next;
    }
    pt->next=ptr;
    ptr->next=head;
    head=ptr;
    
}
void Insertion_tail(node *&head, int n)
{
    if (head == NULL)
    {   Inserttion_atfirst(head,n);
    return;
    }
    node *ptr = new node(n);
    node *pt = head; 
    while (pt->next != head)
    {
        pt = pt->next;
    }
    pt->next = ptr;
     ptr->next=head; 
}
void display(node *head)
{   node *pt=head;
    do
    {    cout<<pt->data<<" ";
         pt=pt->next;
    } while (pt!=head);
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
    Inserttion_atfirst(head,2);
    display(head);
    
    return 0;
}