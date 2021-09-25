#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
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

    ListNode *reverseIT(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        ListNode *nxt = head->next;
        while (curr != nullptr)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if (nxt == nullptr)
                continue;
            nxt = nxt->next;
        }
        head = prev;
        return head;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverseIT(l1);
        l2 = reverseIT(l2);
        ListNode *a = l1;
        ListNode *b = l2;
        while (1)
        {
            a->val = a->val + b->val;
            if (a->next != nullptr && b->next != nullptr)
            {
                a = a->next;
                b = b->next;
                continue;
            }
            if (a->next == nullptr && b->next == nullptr)
                break;
            if (a->next != nullptr && b->next == nullptr)
                break;
            if (a->next == nullptr && b->next != nullptr)
            {
                a->next = b->next;
                break;
            }
        }

        int c = 0;
        a = l1;
        while (a != nullptr)
        {
            if (a->val + c > 9)
            {

                if (a->next != nullptr)
                {
                    a->val = (c + a->val) % 10;
                    c = 1;
                }
            }
            else if (a->val + c < 10)
            {
                a->val = c + a->val;
                c = 0;
            }
            if (a->next != nullptr)
            {
                a = a->next;
                continue;
            }
            if (a->val + c < 10)
            {
                break;
            }
            else
            {
                a->val = (a->val + c) % 10;
                ListNode *last = new ListNode;
                last->val = 1;
                a->next = last;
                last->next = nullptr;
                break;
            }
        }
        l1 = reverseIT(l1);
        return l1;
    }
};
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    int index = 0;
    for (int i = 0; i < lists.size(); i++)
    {
        ListNode *n = lists[i];
        if (n == nullptr)
            continue;
        heap.push({n->val, i});
    }

    ListNode *ans = nullptr;
    ListNode *back = nullptr;

    while (!heap.empty())
    {
        auto p = heap.top();
        heap.pop();
        ListNode *node = lists[p.second];
        if (node == nullptr)
            continue;
        if (ans == nullptr)
        {
            ans = back = node;
            if (node->next != nullptr)
            {
                heap.push({node->next->val, p.second});
                lists[p.second] = lists[p.second]->next;
            }
        }
        else
        {
            back->next = node;
            back = back->next;
            if (node->next != nullptr)
            {
                heap.push({node->next->val, p.second});
                lists[p.second] = lists[p.second]->next;
            }
        }
    }
    back->next = nullptr;
    return ans;
}
int main()
{
    using namespace std;
    ListNode *l1 = new ListNode;
    l1->val = 1;
    ListNode *l11 = new ListNode;
    l11->val = 4;
    ListNode *l12 = new ListNode;
    l12->val = 5;

    l12->next = nullptr;
    l11->next = l12;
    l1->next = l11;

    ListNode *pl11 = new ListNode;
    pl11->val = 1;
    ListNode *pl12 = new ListNode;
    pl12->val = 3;
    ListNode *pl13 = new ListNode;
    pl13->val = 4;
    pl12->next = pl13;
    pl11->next = pl12;

    ListNode *apl11 = new ListNode;
    apl11->val = 2;
    ListNode *apl12 = new ListNode;
    apl12->val = 6;
    apl11->next = apl12;

    vector<ListNode *> lists{l1, pl11, apl11};
    mergeKLists(lists);
    // Solution s;
    // ListNode *q = new ListNode;
    // q->val = 5;
    // ListNode *w = new ListNode;
    // w->val = 5;
    // s.addTwoNumbers(q, w);
    return 0;
}