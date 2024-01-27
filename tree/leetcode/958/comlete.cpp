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
    bool lavelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool isNullFound = false;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front == NULL)
                isNullFound = true;
            else
            {
                if (isNullFound)
                    return false;
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode *root)
    {
        return lavelOrder(root);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
