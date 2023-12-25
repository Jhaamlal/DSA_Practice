#include <iostream>
#include <queue>
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
// Pre order traversal
/*
Pre order traversal => 	// N L R
In this it will first traverse the Right side of the data
In second it will traverse the right side of data
*/
void preOrderTraversal(Node *root)
{
    // First print the root
    cout << root->data << " ";

    // Left side
    preOrderTraversal(root->left);

    // Right side
    preOrderTraversal(root->right);
}
// Post order traversal
/*
LRN => Left right and Node
=>  Well in this left and right side is traversed then we talk about the LRN
=>  Then we put the node  which is just opposite to preOrder traversal
*/
void postOrderTraversal(Node *root)
{
    // left side of the data
    postOrderTraversal(root->left);

    // Right side of the data
    postOrderTraversal(root->right);

    // Printing the node
    cout << root->data << " ";
}

// in order order traversal
/*
  LNR => Left,node,Right
  It is not much different then other is just that ,in this node is printed in the middle of the element
*/

void inOrderTraversal(Node *root)
{
    // First left side of the element
    inOrderTraversal(root->left);

    // Next root of the element
    cout << root->data << " ";

    // Right side of the element
    inOrderTraversal(root->right);
}

/*
Level order traversal
In this , we are adding null so that we can print the data
in the  layer ,means one at the top . Nothing more thing less
*/
void levelOrderTraversal(Node *root)
{
    // Que is type which store the nodes
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        // Null is border that divide the next level to other level
        if (front == NULL)
        {
            // shift to next line
            cout << endl;
            if (!q.empty())
                // You got null means that that particular level of element has been exulted there
                q.push(NULL);
        }
        else
        {
            // Print the element to that level
            cout << front->data << " ";

            // As they are right and left to the element then they are are the
            // Next level to the element of the item
            // Then push the element to the next level
            if (front->left != NULL)
                q.push(front->left);

            if (front->right != NULL)
                q.push(front->right);
        }
    }
}

int main()
{
    /* code */
    return 0;
}
