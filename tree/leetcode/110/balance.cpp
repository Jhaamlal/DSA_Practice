// https://leetcode.com/problems/balanced-binary-tree/submissions/1123324869
#include <iostream>
#include <queue>
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

class Solution
{
public:
    int height(TreeNode *root)
    {
        // base case
        if (root == NULL)
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int height = max(leftHeight, rightHeight) + 1;
        return height;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;

        //
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int difference = abs(rightHeight - leftHeight);

        bool currentAns = difference <= 1;

        int leftAns = isBalanced(root->left);
        int rightAns = isBalanced(root->right);

        if (currentAns && leftAns && rightAns)
            return true;
        else
            return false;
    }
};

int main()
{
    /* code */
    return 0;
}
