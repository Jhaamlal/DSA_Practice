// https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/1134752367
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
=> One of the important point I have learned here is that
  if (root == NULL)
            return new TreeNode(val);

this can use as base case and the edge case also
you don't need to check for the root->right or root->left

*/

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};

main()
{
    /* code */
    return 0;
}
