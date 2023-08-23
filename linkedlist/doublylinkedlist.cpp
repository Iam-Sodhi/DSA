#include <iostream>
using namespace std;
class node{
    public: int data;
            node* next;
            node* prev;
            node(int n){
                data=n;
                next=NULL;
                prev=NULL;
            }
};
void Insertion_athead(node* &head,int n){
    node *ptr= new node(n);
    ptr->next=head;  // if head = null  then ptr->next=null

    if (head!=NULL)   // it is done as if head==null, then we can't go to null->prev
    {                 // ptr->prev is already null by constructor
      head->prev=ptr;
    }
    head= ptr;

}
void Insertion_tail(node* &head, int n){
    node* ptr=new node(n);
    if (head==NULL)
    {
        Insertion_athead(head,n);
        return;
    }
    node *temp= head;
    while (temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
    //ptr->next=NULL // no need as constructor already did it
}
void delete_athead(node* &head){
    node *temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
}
void deletion(node* &head, int index){
    if(index==0){
        delete_athead(head);
        return;
    }
    int i=0;
    // here we will bring the pointer exactly on the position not on the previous node
    node *temp=head;
    while (i!=index)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next; // here temp->next will point to null
    if (temp->next!=NULL) // if the element is last then temp->next will be null so temp->next->prev will be invalid
    {
          temp->next->prev=temp->prev;
    }
    delete temp;
}
void display(node* head){
    node *temp=head;
    while (temp!=NULL)
    {   cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}
int main()
{	  node * head= NULL;
      Insertion_tail(head, 5);
      Insertion_tail(head, 9);
      Insertion_tail(head, 23);
      Insertion_tail(head, 34);
      Insertion_tail(head, 98);
      Insertion_tail(head, 56);
      display(head);
      Insertion_athead(head, 88);
      display(head);
      deletion(head,3);  // here 3 is index not position
      display(head);
    deletion(head,0);
    //   or
    //    delete_athead(head);
      display(head);
    return 0;
}