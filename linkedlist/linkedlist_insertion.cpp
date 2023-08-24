#include <iostream>
using namespace std;
class node{
    public: int data;
            node *next;
            node(){}
            node(int n){
                data=n;
            }

};
void traversal( node * head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head= head->next;
    }
    
}
node *Insert_first( node *head, int n){
    node * ptr= new node(n);
    ptr->next=head;
    return ptr;
}
void Insert_between(node *head, int index, int n){
    node *ptr= new node(n);
    node *pt= head; // here to we need to return head as it is so we will preserve it
    int i=0;
    while (i!=index-1)
    {
        pt= pt->next;
        i++;
    }
    ptr->next= pt->next;
    pt->next= ptr;
   
}
void Insert_end(node* head, int n){
    node *ptr=new node(n);
    node * pt= head;
    while (pt->next!=0)
    {
        pt = pt->next;
    }
    pt->next=ptr;
    ptr->next=NULL;
    
    
}
void Insert_afternode(node *prevnode, int n){
    node *ptr= new node(n);
    ptr->next=prevnode->next;
    prevnode->next=ptr;
}

int main()
{	 node * first= NULL;
    //  node *second = new node(7);
    //  node *third= new node(9);
    //  first->next=second;
    //  second->next=third;
    //  third->next=NULL;
     traversal(first);
    //  //Insert at beginning
      first= Insert_first(first, 1);
     cout<<"\nAfter inserting at first:"<<endl;
  traversal(first);
     //Insert in between
     Insert_between(first,2,19); // here 2 is the index number
     cout<<"\nAfter inserting in between:"<<endl;
     traversal(first);
     //Insert at end
     Insert_end(first, 34);
     cout<<"\nAfter inserting at the end:"<<endl;
     traversal(first);
     //Insert after given node
     Insert_afternode(first,60);
     cout<<"\nAfter inserting after the node:"<<endl;
     traversal(first);



    return 0;
}