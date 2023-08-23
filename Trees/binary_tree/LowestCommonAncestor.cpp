#include <iostream>
#include <vector>
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
// There are two methods-> both have same time complexibility O(n)
node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *Left = lca(root->left, n1, n2);
    node *right = lca(root->right, n1, n2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }

    if (left != NULL)
    {
        return lca(root->left, n1, n2);
    }
    if (right != NULL)
    {
        return lca(root->right, n1, n2);
    }
}

// Method 2
bool getpath(node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }
    if (getpath(root->left, key, path) || getpath(root->right, key, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}
int lca2(node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!getpath(root, n1, path1) || !getpath(root, n2, path2))
    {
        return -1;
    }
    int pc;
    for (pc = 0; (pc < path1.size() && path2.size()); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }
    return path1[pc - 1];
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
    node *LCA = lca(root, 5, 7);
    cout << LCA->data << endl;
    LCA = lca(root, 4, 5);
    cout << LCA->data << endl;
    //using method2
    cout<<endl<<lca2(root,2,7)<<endl;
    return 0;
}