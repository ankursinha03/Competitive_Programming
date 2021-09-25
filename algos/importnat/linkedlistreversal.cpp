#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *endNode(ListNode *start, int n)
{
    if (start == nullptr)
        return start;
    ListNode *ans;
    ans = start;
    while (n--)
    {
        ans = ans->next;
        if (ans == nullptr)
            break;
    }
    return ans;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head->next == nullptr)
        return head;

    ListNode *n = head;
    ListNode *prev = nullptr;
    ListNode *nxt;
    ListNode *temp;
    ListNode *x;
    ListNode *t;
    ListNode *e;
    k--;
    while (1)
    {
        x = n;
        e = endNode(n, k);
        if (e == nullptr)
            return head;

        temp = e->next;
        nxt = n->next;
        if (prev != nullptr)
        {
            prev->next = e;
        }
        n->next = temp;
        while (n != e)
        {
            t = nxt->next;
            nxt->next = n;
            n = nxt;
            nxt = t;
        }
        if (prev == nullptr)
        {
            head = e;
        }
        n = temp;
        prev = x;
    }
    return head;
}
ListNode *reverseList(ListNode *l)
{
    ListNode *prev = NULL;

    while (l)
    {
        ListNode *temp = l->next;
        l->next = prev;
        prev = l;
        l = temp;
    }
    return prev;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == nullptr || head->next == nullptr || left == right)
        return head;

    ListNode *start = head;
    ListNode *startPrev = nullptr;
    ListNode *end = head;

    ListNode *temp;
    ListNode *startNxt;

    while (--left)
    {
        startPrev = start;
        start = start->next;
    }
    while (--right)
    {

        end = end->next;
    }
    startNxt = start->next;
    start->next = end->next;
    ListNode *x;
    x = startNxt;
    startNxt = startNxt->next;
    x->next = start;
    while (x != end)
    {
        start = x;
        x = startNxt;

        startNxt = startNxt->next;
        x->next = start;
    }

    if (startPrev == nullptr)
    {
        head = end;
    }
    else
    {
        startPrev->next = end;
    }

    return head;
}

int main()
{
    using namespace std;
    ListNode *head = new ListNode;
    head->val = 1;
    ListNode *hea = new ListNode;
    hea->val = 2;
    ListNode *he = new ListNode;
    he->val = 3;
    ListNode *h = new ListNode;
    h->val = 4;
    ListNode *l = new ListNode;
    l->val = 5;
    h->next = l;
    he->next = h;
    hea->next = he;
    head->next = hea;
    reverseBetween(head, 2, 4);

    return 0;
}