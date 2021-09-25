#include <iostream>

using namespace std;

class LIST
{
    int p[100];
    int start;
    int end;

public:
    LIST()
    {
        start = 0;
        end = -1;
    }
    void add(int a)
    {
        if (end == 99)
        {
            cout << "\nThe LIST is full\n";
        }
        else
        {
            end++;
            p[end] = a;
        }
    }
    void find(int x)
    {
        int i = start;
        while (i <= end)
        {
            if (p[i] == x)
            {
                cout << "\n the location is: " << i;
                break;
            }
            i++;
        }
        if (i > end)
        {
            cout << "\nelement not found!!\n";
        }
    }
    void findkth(int x)
    {
        if (x <= end)
        {
            cout << "\n"
                 << p[x];
        }
        else
        {
            cout << "\n\nentered position is empty or invalid\n";
        }
    }
    void print_list()
    {
        if (start <= end)
        {
            cout << endl;
            cout << "\nthe current list is: ";
            for (int i = start; i <= end; i++)
            {
                cout << p[i] << " ";
            }
        }
        else
        {
            cout << "\n\n empty list";
        }
    }
    void pop()
    {
        if (start < end)
        {

            cout << "poping: " << p[start];
            start++;
        }
        else if (start == end)
        {
            cout << "poping: " << p[start];
            start = 0;
            end = -1;
        }
        else
        {
            cout << "\n\n empty list\n";
        }
    }
    void addInPos(int x, int n)
    {
        if (end == 99)
        {
            cout << "\nno space to add\n";
        }
        else
        {
            if (n > end)
            {
                cout << "\nenter a valid position \n";
            }
            else
            {
                for (int i = end; i >= n; --i)
                {
                    p[i + 1] = p[i];
                }
                p[n] = x;
                cout << "\n added sucessfully!\n";
                end++;
            }
        }
    }
    void del(int n)
    {
        if (n < start || n > end)
        {
            cout << "\nenter valid position\n";
        }
        if (n == start)
        {
            start++;
        }
        else
        {
            for (int i = n; i <= end; i++)
            {
                p[n] = p[n + 1];
            }
            end--;
        }
    }
};

int main()
{
    LIST lst;
    int a;

    while (a != -1)
    {
        cout << "\n1 to add\n2 to find\n3 to print\n4 to find element at k\n5 to pop\n6 add in poistion\n7 delete the position \n-1 to quit ";
        cin >> a;
        switch (a)
        {

        case 1:
        {
            cout << "\nenter to add: ";
            int y;
            cin >> y;
            lst.add(y);
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
            lst.print_list();
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
            int a, b;
            cout << "\n enter element and poistion: ";
            cin >> a >> b;
            lst.addInPos(a, b);
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
        default:
            break;
        }
    }
    return 0;
}
