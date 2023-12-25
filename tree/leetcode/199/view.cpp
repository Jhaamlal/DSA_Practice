// https://leetcode.com/problems/binary-tree-right-side-view/submissions/1125830023
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
    void solve(TreeNode *root, vector<int> &ans, int level)
    {
        if (root == NULL)
            return;

        if (ans.size() == level)
            ans.push_back(root->val);
        level++;
        solve(root->right, ans, level);
        solve(root->left, ans, level);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans = {};
        int level = 0;
        solve(root, ans, level);
        return ans;
    }
};

int main()
{
    // Create nodes
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Create Solution object and call function
    Solution solution;
    vector<int> result = solution.rightSideView(root);

    // Print the result
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] == NULL)
        {
            cout << "NULL ";
        }
        else
        {
            cout << result[i] << " ";
        }
    }

    return 0;
}
