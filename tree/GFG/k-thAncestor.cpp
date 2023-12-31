#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
Node *solve(Node *root, int &k, int node, int &ans)
{
    if (!root)
        return 0;

    if (root->data == node)
        return root;

    Node *left = solve(root->left, k, node, ans);

    Node *right = solve(root->right, k, node, ans);

    if (!right && !left)
        return 0;

    k--;

    if (k == 0)
        ans = root->data;

    if (right && !left)
        return right;

    if (left && !right)
        return left;
    else
        return root;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans = -1;
    solve(root, k, node, ans);
    return ans;
}
int main()
{
    /* code */
    return 0;
}
