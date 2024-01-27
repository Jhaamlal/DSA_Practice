#include <iostream>
using namespace std;
//  * Definition for a binary tree node.
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
=> Valid BST is bst ,that contain all the children that is lower then the parent node
=> Valid BST is that contain all the children that is higher then that
=> At root range is minus infinity ,to plus infinity
=> if when go left side, in that case range is  (-infinity ,root) => (root,infinity )

psudo code
if root == null return null;
if left,max (root) ,in min (root)

*/

class Solution
{
public:
    bool solve(TreeNode *root, int min, int max)
    {
        if (root == NULL)
            return true;

        // single case solve
        if (root->val >= min && root->val <= max)
            return true;

        bool leftAns = solve(root->left, min, root->val);
        bool rightAns = solve(root->right, root->val, max);

        if (leftAns && rightAns)
            return true;
        else
            return false;
    }
    bool isValidBST(TreeNode *root)
    {
        return solve(root, INT_MIN, INT_MAX);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
