#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node() {}
    node(int n)
    {
        data = n;
    }
};
void traversal(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void Delete_first(node *&head)
{
    node *ptr = head;
    head = ptr->next;
    delete ptr; // to prevent memory leak
     
}
void Deletion(node * &head, int n)
{  if (head==NULL)       //to check the condition when list is empty
{
    return;
}

    if (head->next==NULL)  // it is to check the condition when there is only one element present
    {
        Delete_first(head);
        return;
    }
    
    node *ptr = head;
    while ((ptr->next->data != n) && (ptr->next != NULL))  // it will also check the condition when no element with the given value is presents
    {
        ptr = ptr->next;
    }
   if (ptr->next->data==n)     // in case none of the element matches the given value , then no deletion
   {
    node *pt = ptr->next;
    ptr->next = pt->next;
    delete pt;
   }
    else
    {
        return;
    }
    
}
void Delete_end(node *&head)
{
    node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    node *pt = ptr->next;
    ptr->next = NULL;
    delete pt;
}
void Delete_index(node *&head, int index)
{
   node * ptr= head;
   for (int i = 0; i < index-1; i++)
   {
     ptr= ptr->next;
   }
   node *pt= ptr->next;
   ptr->next= ptr->next->next;
   delete pt;
   
}

int main()
{
    node *first = new node(4);
    node *second = new node(7);
    node *third = new node(9);
    node *fourth=new node(16);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next=NULL;
    traversal(first);
    //     //  //Delete at beginning
    //       Delete_first(first);
    //      cout<<"\nAfter deleting at beginning:"<<endl;
    //   traversal(first);
    // Delete a given value
    Deletion(first, 7);
    cout << "\nAfter Deleting the given value:" << endl;
    traversal(first);
    //  //Delete at end
    //  Delete_end(first);
    //  cout<<"\nAfter deleting at the end:"<<endl;
    //  traversal(first);
    //  //Deleting at index
    //  Delete_index(first,2);
    //  cout<<"\nAfter inserting after the node:"<<endl;
    //  traversal(first);

    return 0;
}