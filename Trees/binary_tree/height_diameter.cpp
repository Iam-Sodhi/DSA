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
int height_BT(node *root) // O(n)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height_BT(root->left), height_BT(root->right)) + 1;
}
// Diameter is no. of nodes in the longest path b/w any 2 leaves
int diamter_BT(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int currD = height_BT(root->left) + height_BT(root->right) + 1; // O(n^2)
    int leftD = diamter_BT(root->left);
    int rightD = diamter_BT(root->right);
    return max(currD, max(leftD, rightD));
}
// There is a better approach in which we use pointer(height) instead of using another function to find height
// int diameter_BT(node *root, int *height)
// {
//     if (root == NULL)
//     {
//         *height = 0;
//         return 0;
//     }
//     int lh = 0, rh = 0;
//     int leftD = diameter_BT(root->left, &lh);
//     int rightD = diameter_BT(root->right, &rh);
//     int currD = lh + rh + 1;
//     *height = max(lh, rh) + 1;

//     return max(currD, max(leftD, rightD));
// }
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
    cout << height_BT(root) << endl;
    cout << diamter_BT(root) << endl;
    return 0;
}