#include <iostream>
#include <stack>
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
void zigzag_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> currLevel, nextLevel;
    bool lefttoRight = true;
    currLevel.push(root);
    while (!currLevel.empty())
    {
        node *temp = currLevel.top();
        currLevel.pop();
        if (temp)
        {
            cout << temp->data << " ";

            if (lefttoRight)
            {
                if (temp->left != NULL)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    nextLevel.push(temp->right);
                }
            }
            else // right to left
            {
                if (temp->right != NULL)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    nextLevel.push(temp->left);
                }
            }
        }

        if (currLevel.empty())
        {
            lefttoRight = !lefttoRight;
            swap(currLevel,nextLevel);
        }
    }
}

void print_preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}
int main()
{
    node *root = new node(5);
    root->left = new node(2);
    root->right = new node(8);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(9);
    /* 5
     / \
    2   8
   / \   \
  1   3   9
  */
    zigzag_traversal(root);
    return 0;
}