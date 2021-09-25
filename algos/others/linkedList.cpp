#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
struct node
{
    int data = 0;
    node *next = nullptr;
};
class LinkedList
{
    node *start = nullptr;

protected:
    void PRINT_REVERSE(node *n)
    {
        if (n == nullptr)
            return;
        PRINT_REVERSE(n->next);
        std::cout << n->data << " ";
    }

public:
    LinkedList(int DATA)
    {
        if (start == nullptr)
        {
            node *newNode = new node;
            newNode->data = DATA;
            start = newNode;
        }
    }
    void insert(int DATA)
    {
        node *newNode = new node;
        newNode->data = DATA;
        newNode->next = start;
        start = newNode;
    }
    void print()
    {
        node *n;
        n = start;
        printf("\n");
        if (n == nullptr)
        {
            std::cout << "\nEMPTY :(\n";
        }
        while (n != nullptr)
        {
            std::cout << n->data << " ";
            n = n->next;
        }
    }
    void reverse()
    {
        node *curr = start;
        node *prev = nullptr;
        node *next;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        start = prev;
    }
    void printRevese()
    {
        printf("\n");
        PRINT_REVERSE(start);
    }
    bool if_palindrome()
    {
        stack<int> st;
        node *n;
        n = start;
        while (n != nullptr)
        {
            st.push(n->data);
            n = n->next;
        }
        n = start;
        while (n != nullptr)
        {
            if (n->data != st.top())
                return false;
            n = n->next;
            st.pop();
        }
        return true;
    }
    void del()
    {
        node *n;
        n = start;
        node *next;
        while (n != nullptr)
        {
            next = n->next;
            delete (n);
            n = next;
        }
        start = nullptr;
    }
    bool is_looped()
    {
        node *s;
        node *f;
        s = f = start;
        while (1)
        {
            s = s->next;
            if (f == nullptr || f->next == nullptr)
            {
                break;
            }
            f = f->next->next;

            if (s == nullptr)
            {
                break;
            }
            if (s == f)
                return true;
        }
        return false;
    }
    void deletAlternateNode()
    {
        node *s = start;
        node *a = start;
        node *b = a->next->next;
        node *temp;
        while (b != nullptr && a->next != nullptr && a != nullptr)
        {
            temp = a->next;
            a->next = b;
            delete (temp);
            a = b;
            if (b->next == nullptr)
                break;
            b = a->next->next;
        }
    }
    void rotate(int k)
    {

        node *temp;
        node *end;
        end = start;
        while (end->next != nullptr)
        {
            end = end->next;
        }

        while (k--)
        {
            end->next = start;
            temp = start;
            start = start->next;
            temp->next = nullptr;
            end = end->next;
        }
        node *x = start;
    }
};
node *findIntersection(node *head1, node *head2)
{
    node *ans = nullptr;
    node *last = ans;
    node *start1;
    node *start2;
    start1 = head1;
    start2 = head2;
    while (start1 != nullptr && start2 != nullptr)
    {
        if ((int)start1->data < (int)start2->data)
        {
            start1 = start1->next;
        }
        else if ((int)start1->data > (int)start2->data)
        {
            start2 = start2->next;
        }
        else
        {
            if (ans == nullptr)
            {
                node *n = new node;
                n->data = start1->data;
                ans = n;
                last = n;
            }
            else
            {
                node *nN = new node;
                nN->data = start1->data;

                last->next = nN;
                last = nN;
            }
            start1 = start1->next;
            start2 = start2->next;
        }
    }
    return ans;
}
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int numComponents(ListNode *head, vector<int> &nums)
{

    // int count=0;
    //     unordered_set<int>s(G.begin(),G.end());
    //     while(head!=NULL)
    //     {
    //         int f=0;
    //         while(head!=NULL&&s.find(head->val)!=s.end())
    //         {
    //             f=1;
    //             head=head->next;
    //         }
    //         if(f)
    //         count++;
    //         if(head!=NULL)
    //         head=head->next;
    //     }
    //     return count;

    int ans = 0;
    ListNode *n = head;
    unordered_map<int, bool> m;

    for (int x : nums)
        m[x] = 1;

    while (n != nullptr && n->next != nullptr)
    {
        auto i = m.find(n->val);

        if (n->next == nullptr)
            break;

        auto k = m.find(n->next->val);
        if (i != m.end(), k != m.end())
        {
            ans++;
            m.erase(i);
            m.erase(k);
        }
        n = n->next;
    }
    if (!m.empty())
    {
        ans += m.size();
    }

    return ans;
}

int main()
{
    using namespace std;
    ListNode *head = new ListNode;
    head->val = 5;
    ListNode *he = new ListNode;
    he->val = 6;
    ListNode *h = new ListNode;
    h->val = 7;
    he->next = h;
    head->next = he;

    vector<int> v = {5, 6};
    numComponents(head, v);

    // LinkedList ll(25);
    // ll.insert(20);
    // ll.insert(15);
    // ll.insert(10);
    // ll.insert(5);
    // ll.print();
    // ll.reverse();
    // ll.print();
    // ll.printRevese();
    // printf("\n");

    // ll.print();
    // ll.rotate(3);
    // ll.print();

    // printf("\n");
    // std::cout << ll.if_palindrome();
    // printf("\n");
    // std::cout << ll.is_looped();
    // ll.deletAlternateNode();
    // ll.print();
    // ll.del();
    // ll.print();

    // LinkedList lll(40);
    // lll.insert(30);
    // lll.insert(20);
    // lll.insert(10);

    // node *a = ll.start;
    // node *b = lll.start;
    // node *ans = findIntersection(a, b);
    // node *n;
    // n = ans;
    // printf("\n");
    // if (n == nullptr)
    // {
    //     std::cout << "\nEMPTY :(\n";
    // }
    // while (n != nullptr)
    // {
    //     std::cout << n->data << " ";
    //     n = n->next;
    // }
    return 0;
}