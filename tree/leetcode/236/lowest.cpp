// https : // leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/1132021183
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
=> In this strategy We make the item
=> first we need to find the P and Q

*/

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root == p)
            return p;
        if (root == q)
            return q;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL && right == NULL)
            return NULL;
        else if (left == NULL && right != NULL)
            return right;
        else if (right == NULL && left != NULL)
            return left;
        else
            return root;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
