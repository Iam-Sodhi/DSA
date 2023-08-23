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
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
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
    fourth->next = NULL;
    display(first);

    return 0;
}