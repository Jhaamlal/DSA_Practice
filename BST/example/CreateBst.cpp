#include <iostream>
using namespace std;

/*
Binary search tree is tree in which , we add the left side ,that is lower value to the what is at the root
We add the Higher value of data in the data , when we add the
*/

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
Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        Node *root = new Node(data);
        return root;
    }
    if (root->data > data)

        // agin made mistake
        // Root is create above ,now you need to add the
        // you need to attach the element to the left and right dide
        root->left = insertIntoBST(root->left, data);
    else
        root->right = insertIntoBST(root->right, data);

    return root;
}
void createBST(Node *&root)
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter data:" << endl;
        cin >> data;
    }
}

// Min value in the BST
// This is the most simple thing in this world ,left most item
Node *minValue(Node *root)
{
    // You increase the temp value as it is
    // There
    if (root == NULL)
        return NULL;
    Node *temp = root;
    while (temp->left != NULL)
    {

        temp = temp->left;
    }
    return temp;
}

Node *maxVal(Node *root)
{
    // You increase the temp value as it is
    // There
    if (root == NULL)
        return NULL;
    Node *temp = root;
    while (temp->right != NULL)
    {

        temp = temp->right;
    }
    return temp;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    return 0;
}
