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
int length(node *head)
{
    int len = 1;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
node* append_lastKnodes(node* &head, int k)
{
    node* newtail;
    node* newhead;
    node* tail = head;
    int count = 1;
    int l = length(head);
    
    k = k % l; // it is to for cases where k>l
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newtail = tail;
        }

        if (count == l - k + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}

int main()
{
    node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        Insertion_tail(head, arr[i]);
    }
    display(head);
    cout<<length(head)<<endl;
    head=append_lastKnodes(head, 3);
    display(head);

    return 0;
}
