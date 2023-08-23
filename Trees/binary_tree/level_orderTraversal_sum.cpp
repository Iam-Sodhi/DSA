#include <iostream>
#include <queue>
using namespace std;
// Level order Traversal ans sum at level k
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
int level_traversal_sum(node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int sum = 0;
    int l = 0; // level

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *N = q.front();
        q.pop();
        if (N != NULL)
        {
            if (l == k)
            {
                sum += N->data;
            }

            cout << N->data << " ";
            if (N->left)
            {
                q.push(N->left);
            }
            if (N->right)
            {
                q.push(N->right);
            }
        }
        else if (!q.empty()) // means N==NULL and after popping q is not empty
        {
            q.push(NULL);
            l++;
        }
    }
   cout << endl;
    return sum;
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
   cout<<level_traversal_sum(root, 2);
    return 0;
}