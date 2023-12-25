#include <iostream>
#include <queue>
#include <vector>
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

vector<vector<int>> levelOrderTraversal(TreeNode *root)
{
    // For level order traversal you need to add the

    queue<TreeNode *> q;
    vector<int> subAns;
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    q.push(root);
    q.push(NULL);
    /*
    Why Q has been ,add that data structure that is there
    Where you can store the data ,in that form .

    */
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();
        if (front == NULL)
        {
            // Because if you have reached there you are here to have
            // This is where the item need to alag
            cout << endl;
            ans.push_back(subAns);
            subAns.clear();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->val << " ";
            subAns.push_back(front->val);
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    levelOrderTraversal(root);
    return 0;
}
