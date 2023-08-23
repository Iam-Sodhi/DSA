#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int n){ 
        data=n;
    }
};
void display(node *head)
{
    node *temp = head;
   do
   {
    cout<<temp->data<<" ";
    temp=temp->next;
   } while (temp!=head);
   cout<<endl;
}
void Insert_atfirst(node* &head, int n){
    node *ptr=new node(n);
    node*pt=head;
    while (pt->next!=head)
    {
        pt=pt->next;
    }
    //at this point, pt points at the last element of the circluar linked list
    pt->next=ptr;
    ptr->next=head;
    head=ptr; // this is to assign value (it will work as we passed by address)
}
void Insert_atend(node* &head, int n){
    node *ptr= new node(n);
    node* pt=head; while (pt->next!=head)
    {
        pt=pt->next;
    }
    //at this point, pt points at the last element of the circluar linked list
    pt->next=ptr;
    ptr->next=head;
   // head=head; // here this will work
   
}
void Insert_aftervalue(node* &head, int val,int n){
    node* ptr=new node(n);
    node* pt=head;
    while ((pt->data!=val) &&(pt->next!=head))
    {
        pt=pt->next;
    }
    ptr->next=pt->next;
    pt->next=ptr;
}
int main()
{
    node *first = new node(4);
    node *second = new node(6);
    node *third = new node(9);
    node *fourth = new node(10);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = first;
    display(first);
    Insert_atfirst(first,54);
    Insert_atfirst(first,89);
    display(first);
    Insert_atend(first,90);
    display(first);
    Insert_aftervalue(first,9,50); 
    display(first);
    return 0;
}