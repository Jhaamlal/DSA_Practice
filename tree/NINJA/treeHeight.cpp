#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int heightOfBinaryTree(TreeNode<int> *root)
{
    // if root null
    if (root == NULL)
        return 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    int count = 1;

    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                count++;
                q.push(NULL);
            }
        }
        else
        {
            cout << front->val << " ";
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
    return count;
}