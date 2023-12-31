#include <iostream>
using namespace std;

/*
=> To delete the node from the node ,you need to understand the some of the item,
=> There are four cases , one after other .
=> Take a target and delete it .

*/
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *maxValue(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    // if tree has nodes > 0 count
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteFromBST(Node *root, int target)
{

    if (root == NULL)
        return NULL;

    if (root->data == target)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // if left element is null and has right element
        if (root->left == NULL && root->right != NULL)
        {
            delete root;
            root = root->right;
            return root;
        }
        // if right element is null and has left element
        if (root->left != NULL && root->right == NULL)
        {
            delete root;
            root = root->left;
            return root;
        }
        // Both left and right element are not null
        if (root->left != NULL && root->right != NULL)
        {
            // If both are not null in that case you need
            // in that case ,you need to get the max value of left
            // min element of right side
            Node *element = maxValue(root->left);
            // you replace the item which you are deleting the
            // From the Item
            root->data = element->data;
            // This janta forget to attach when needed
            root->left = deleteFromBST(root->left, element->data);
            return root;
        }
    }
    // we will not return here as
    // we will return it in last ,
    // are just update and return in last
    if (root->data > target)
    {
        root->left = deleteFromBST(root, target);
    }
    if (root->data < target)
    {
        root->left = deleteFromBST(root, target);
    }
    return root;
    // If it is left and right element is null
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
