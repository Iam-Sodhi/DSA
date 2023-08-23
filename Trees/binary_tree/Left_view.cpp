#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};
void left_view(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *N = q.front();
            q.pop();
            if (i == 0)
            {
                cout << N->data << " ";
            }
            if (N->left!=NULL)
            {
                q.push(N->left);
            }
            if (N->right!=NULL)
            {
                q.push(N->right);
            }
        }
    }
}


int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(7);
    /*  1
      / \
     2   3
    / \   \
   4   5   7
   */
  left_view(root);
    return 0;
}