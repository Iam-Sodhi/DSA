#include <iostream>
using namespace std;  //Important question
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
node* merged(node* head1, node* head2){
    node* p1=head1;
    node* p2=head2;
    node* dummynode=new node(1);// we can put any valu
    node* p3=dummynode;  
    while (p1!=NULL&&p2!=NULL)
    {
        if (p1->data<p2->data)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
        
    }
    while (p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    
    while (p2!=NULL)
    {
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
   p3->next=NULL;
    return dummynode->next;
}
node* merged_Recursive(node* head1,node* head2){
    node* result;
    if (head1==NULL)
    {
        return head2;
    }
    if (head2==NULL)
    {
        return head1;
    }
    
    
  if (head1->data<head2->data)
  {
    result=head1;
    result->next=merged_Recursive(head1->next,head2);
  }
  else
  {
    result=head2;
    result->next=merged_Recursive(head1,head2->next);
  }
  return result;
}
int main(){
	node* head1=NULL;
	node* head2=NULL;
    int arr1[]={3,5,8,10,11};   // two lists should be sorted
    int arr2[]={1,6,15};
    for (int i = 0; i <5; i++)
    {
        Insertion_tail(head1,arr1[i]);
    }
    for (int i = 0; i <3; i++)
    {
        Insertion_tail(head2,arr2[i]);
    }
    display(head1);
    display(head2);
    node* merged_head=merged(head1,head2);
    display(merged_head);
    // node* merged_head2=merged_Recursive(head1,head2);
    // display(merged_head2);
    return 0;
}