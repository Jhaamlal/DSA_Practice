#include <iostream>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // one minimum prority queq
        // go into first coloum row o col
        // how to define that which item has the low item has been removed ?
        // any emlemnt that is removed has next element
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *listHead = lists[i];
            if (listHead != NULL)
                pq.push(listHead);
        }
        // initiating the priority queue

        ListNode *head = NULL;
        ListNode *tail = NULL;
        while (!pq.size())
        {
            ListNode *topNode = pq.top();
            pq.pop();

            // If it is the first element
            // in that case it will become the head and tail
            // once it become head and tail
            // then we need to  see ,if there are some element that are the
            //
            if (head == NULL)
            {
                head = topNode;
                tail = topNode;
                if (tail->next != NULL)
                    pq.push(tail->next);
            }
            else
            {
                tail->next = topNode;
                tail = topNode;
                if (tail->next != NULL)
                    pq.push(tail->next);
            }
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
