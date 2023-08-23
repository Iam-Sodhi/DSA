#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node() {}
    node(int a)
    {
        data = a;
        next = NULL;
    }
   
};
int isEmpty(node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}
int isFull(node *head)
{
    node *ptr = new node();
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}
void push(node *&head, int n)  // in stack, we add from head side not like in queue
{
    node *ptr = new node(n);
    if (isFull(head)) // when heap is completed
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
}
int pop(node * &head)
{
    if (isEmpty(head))
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        node *pt = head;
        head = head->next;
        int x= pt->data;
         free(pt);
        return x;
       
    }
}
 int peak(node* head, int pos){
        int count=1;
        while (count<pos)
        {
            head=head->next;
            count++;
        }
        return head->data;
    }
    int stackTop(node* head){
        return head->data;
    }
    int stackBottom(node* head){
        node* pt=head;
        while (pt->next!=NULL)
        {
            pt=pt->next;
        }
        return pt->data;
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
int main()
{
    node *top = NULL;
    push(top, 4);
    push(top, 6);
    push(top, 9);
    push(top, 11);
    display(top);
   // cout<<isEmpty(top);
    push(top,15);
    display(top);
    cout<<"The popped element is "<<pop(top)<<endl;
    display(top);
    int pos=3;
    cout<<"The element at position "<<pos<<" is "<<peak(top,pos)<<endl;
    cout<<"Using stack top, we get "<<stackTop(top)<<endl;
    cout<<"Using stack bottom, we get "<<stackBottom(top)<<endl;
    return 0;
}