#include <istream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    bool isCompleteBT(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        queue<Node *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            // Ram krishan sharanm
            if (temp->left != NULL)
            {
                if (flag)
                {
                    return false;
                }
                q.push(temp->left);
            }
            else
            {
                flag = true;
            }

            if (temp->right != NULL)
            {
                if (flag)
                {
                    return false;
                }
                q.push(temp->right);
            }
            else
            {
                flag = true;
            }
        }
        return true;
    }
    bool inGreat(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        // Don't forget to check if it's null ot not before checking it
        // Before comparision
        if (root->left != NULL && root->data < root->left->data)
        {
            return false;
        }

        if (root->right != NULL && root->data < root->right->data)
        {
            return false;
        }

        return inGreat(root->left) && inGreat(root->right);
    }
    bool isHeap(struct Node *tree)
    {
        bool isComplete = isCompleteBT(tree);
        bool isRight = inGreat(tree);
        return isComplete && isRight;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
