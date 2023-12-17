#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Middle
{

public:
    Middle(/* args */);
    ListNode getMiddle(ListNode *head)
    {
        ListNode *item = head;
        //
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next != NULL)
        {
        }
    }
};

int main()
{

    return 0;
}
