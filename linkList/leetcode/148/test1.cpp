// https: // leetcode.com/problems/sort-list/
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

class Solution
{
public:
    int middle(ListNode *head)
    {
        ListNode *s = head;
        ListNode *fast = head->next;
        int count = 0;
        while (fast != NULL)
        {
            fast = fast->next;
            s = s->next;
            count++;
        }
        return count;
    }
    int getLinkListLen(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    ListNode *sortList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *count = head;
        int lengthOfNode = getLinkListLen(head);
        int index = 1;

        while (index != lengthOfNode)
        {
            if (temp->next != NULL && temp->val > temp->next->val)
            {
                int tempVal = temp->next->val;
                temp->next->val = temp->val;
                temp->val = tempVal;
            }
        }
    }
};

int main()
{

    return 0;
}
