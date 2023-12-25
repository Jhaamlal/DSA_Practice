// https://leetcode.com/problems/path-sum/submissions/1123397168
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

class Solution
{
public:
    bool solve(TreeNode *root, int targetSum, int sum)
    {
        if (root == NULL)
            return false;
        // at each node sum will be added

        sum = sum + root->val;
        // This is condition for the leaf node
        // Here it is getting all the node item that are not add
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum)
                return true;
            else
                return false;
        }

        int left = solve(root->left, targetSum, sum);
        // Left Path
        int right = solve(root->right, targetSum, sum);

        return left || right;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        /*
        => Need to create a new Function for this reason is that
        => you need to pass the element , sum
        => which calculate the all the item here
        */
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};

int main()
{
    /* code */
    return 0;
}
