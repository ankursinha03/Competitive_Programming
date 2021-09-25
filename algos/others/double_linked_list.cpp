#include <iostream>
using std::cout;
struct node
{
    int value;
    node *next = nullptr;
    node *prv = nullptr;
};
class linkedList
{
    node *start;
    node *end;

public:
    linkedList()
    {
        start = nullptr;
        end = nullptr;
    }

    void add(node &n)
    {

        if (start == nullptr)
        {
            start = &n;
            end = &n;
        }
        else
        {
            n.next = end;
            end->prv = &n;
            end = &n;
        }
    }

    void display()
    {
        if (start == nullptr)
        {
            cout << "\nEmpty list!";
        }
        else
        {
            node *itr = start;
            cout << "\n\n";
            while (itr != nullptr)
            {
                cout << " " << itr->value;
                itr = itr->prv;
            }
        }
        cout << "\n";
    }

    void find(int x)
    {
        if (start == nullptr)
        {
            cout << "\nEmpty list!";
        }
        else
        {
            int count = 0;
            int flag = 0;
            node *itr = start;
            while (itr != nullptr)
            {
                if (itr->value == x)
                {
                    cout << "\nfound at :" << count;
                    flag = 2;
                    break;
                }
                count++;
                itr = itr->prv;
            }
            if (flag == 0)
            {
                cout << "\nelement not found";
            }
        }
    }

    void findkth(int k)
    {
        int count = 0;
        node *itr = start;
        while (itr != nullptr)
        {
            if (count == k)
            {
                cout << "\nthe value of the element in the position is: " << itr->value;
                break;
            }
            count++;
            itr = itr->prv;
        }
    }

    void pop()
    {
        if (start == nullptr)
        {
            cout << "\nEMPTY LIST";
        }
        else
        {
            start = start->prv;
        }
    }

    void addInPos(node &a, int b)
    {
        node *itr = start;
        int count = 0;
        while (itr != nullptr)
        {
            if (b == 0)
            {
                itr->next = &a;
                a.prv = itr;
                start = &a;
                break;
            }
            if (itr == end)
            {
                itr->prv = &a;
                a.next = itr;
                break;
            }
            if (count == b)
            {
                (itr->next)->prv = &a;
                a.next = itr->next;
                a.prv = itr;
                itr->next = &a;
                break;
            }
            count++;
            itr = itr->prv;
        }
        cout << "\nADDED SUCESSFULLY";
    }

    void del(int n)
    {
        node *itr = start;
        int count = 0;
        while (itr != nullptr)
        {
            if (n == 0)
            {
                (itr->prv)->next = nullptr;
                start = itr->prv;
                itr->prv = nullptr;
                delete itr;
                break;
            }
            if (itr == end)
            {
                (itr->next)->prv = nullptr;
                end = itr->next;
                itr->next = nullptr;
                delete itr;
                break;
            }
            if (count == n)
            {
                (itr->prv)->next = itr->next;
                (itr->next)->prv = itr->prv;
                break;
            }
            count++;
            itr = itr->prv;
        }
        cout << "\nDELETED SUCESSFULLY";
    }
};

int main()
{
    using namespace std;

    linkedList lst;

    int a = 0;

    while (a != -1)
    {
        cout << "\n1 to add\n2 to find\n3 to print\n4 to find element at k\n5 to pop\n6 add in poistion\n7 delete the position \n-1 to quit ";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "\nenter to add: ";
            node *y = new node;
            cin >> y->value;
            lst.add(*y);
            break;
        }
        case 2:
        {
            int x;
            cout << "enter element to be found: ";
            cin >> x;
            lst.find(x);
            break;
        }
        case 3:
        {
            lst.display();
            break;
        }
        case 4:
        {
            int k;
            cout << "\nenter k: ";
            cin >> k;
            lst.findkth(k);
            break;
        }
        case 5:
        {
            lst.pop();
            break;
        }
        case 6:
        {
            node *a = new node;
            int b;
            cout << "\n enter element and poistion: ";
            cin >> a->value >> b;
            lst.addInPos(*a, b);
            break;
        }
        case 7:
        {
            int x;
            cout << "\n enter position to be deleted: ";
            cin >> x;
            lst.del(x);
            break;
        }
        }
    }

    return 0;
}
