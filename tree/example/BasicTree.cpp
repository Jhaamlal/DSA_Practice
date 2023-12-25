#include <iostream>
using namespace std;

/*
=> Just like link list you have create the node ,in which
=> Which save the left and right side node of element
=> At first root node is create ,as we know root node would not contain not have left and right
=> Now next as you can see the recursion part ,it has the data of value ,it's left and right side
=> First it will put the value in the left part and then in the right side of the item
=> And at the end return the root
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

Node *createTree()
{

    cout << "enter the value for Node: " << endl;
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    // Create node
    Node *root = new Node(data);

    // Create left node
    root->left = createTree();

    // create right node
    root->right = createTree();

    return root;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
