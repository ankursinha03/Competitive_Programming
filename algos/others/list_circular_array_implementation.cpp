#include <iostream>

#define len 4
using std::cout;

class CircularArray
{
    int p[len];
    int start;
    int end;

public:
    CircularArray()
    {
        start = -1;
        end = -1;
    }

    void add(int a)
    {
        if (end == -1)
        {
            start++;
            p[start] = a;
            end++;
            return;
        }
        if (start + end == len - 1)
        {
            cout << "\nTHE ARRAY IS FULL COULDN'T ADD !!";
            return;
        }
        if (end + 1 == start)
        {
            cout << "\nTHE ARRAY IS FULL !!";
            return;
        }
        if (start == end)
        {
            end++;
            p[end] = a;
            return;
        }
        if (end + 1 < len)
        {
            end++;
            p[end] = a;
            return;
        }
        if (end == len - 1)
        {
            if (start == 0)
            {
                cout << "\nTHE ARRAY IS FULL!!";
                return;
            }
            else
            {
                end = 0;
                p[end] = a;
            }
        }
    }

    void del()
    {
        if (end == -1)
        {
            cout << "\nEMPTY LIST! NO ELEMENT AVAILABILE FOR DELETE...";
        }
        else if (start == end)
        {
            start = end = -1;
        }
        else
        {
            if (start == len - 1)
            {
                start = 0;
            }
            else
            {
                start++;
            }
        }
    }

    void display()
    {
        cout << "\n";
        int itr = start;
        if (start == -1)
        {
            cout << "\nEMPTY LIST! NOTHING TO DISPLAY";
            return;
        }
        while (itr != end)
        {
            if (itr == len)
            {
                itr = 0;
                continue;
            }
            cout << p[itr] << " ";
            itr++;
        }

        cout << p[end];
    }
};

int main()
{
    using namespace std;
    CircularArray ca;
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
            ca.add(y);
            break;
        }
        case 3:
        {
            ca.display();
            break;
        }
        case 5:
        {
            ca.del();
            break;
        }
        }
    }

    return 0;
}
