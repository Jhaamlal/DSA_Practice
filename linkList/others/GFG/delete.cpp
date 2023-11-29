#include <iostream>
using namespace std;
#include <stack>

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    void linkdelete(struct Node *head, int M, int N)
    {

        if (!head)
            return;

        Node *
            temp = head;

        while (temp != NULL)
        {
            int add = 0;
            int sub = 0;
            Node *prev = temp;
            while (add != M && temp != NULL)
            {
                temp = temp->next;
                prev = temp;
                add++;
            }
            while (sub != N && temp != NULL)
            {
                temp = temp->next;
                sub++;
            }
            prev->next = temp;
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
