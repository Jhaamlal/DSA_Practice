#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrderTraversal(Node *root, vector<int> &ans)
{
    // edge case
    if (root == NULL)
        return;

    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *front = st.top();
        st.pop();
        ans.push_back(front->data);
        /*
        Here I make the mistake of not consider left and Right NULL .
        It must has to do.
        */
        if (front->right != NULL)
            st.push(front->right);
        // Push left child to stack if it is not NULL
        if (front->left != NULL)
            st.push(front->left);
    }
}