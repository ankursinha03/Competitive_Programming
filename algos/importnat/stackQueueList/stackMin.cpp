#include <bits/stdc++.h>
using namespace std;

class STACK
{
    stack<int> S;
    int min;

public:
    void push(int x)
    {
        if (S.empty())
        {
            S.push(x);
            min = x;
        }
        else
        {
            if (x >= min)
            {
                S.push(x);
                S.
            }
            else
            {
                S.push(2 * x - min);
                min = x;
            }
        }
    }
    int pop()
    {
        if (S.empty())
        {
            std::cout << "\n"
                      << "STACK UNDERFLOW";
            return -1;
        }
        int x;
        if (S.top() >= min)
        {
            x = S.top();
            S.pop();
            return x;
        }
        x = min;
        min = 2 * min - S.top();
        S.pop();
        return x;
    }
    int top()
    {
        if (S.empty())
        {
            std::cout << "\n"
                      << "STACK UNDERFLOW";
            return -1;
        }
        int x;
        if (S.top() >= min)
        {
            x = S.top();
            return x;
        }
        x = min;
        return x;
    }
    int mini()
    {
        return min;
    }
};

int main()
{
    using namespace std;

    STACK s;
    s.push(7);
    s.push(8);
    s.push(9);
    std::cout << s.top() << " " << s.mini();
    printf("\n");
    s.push(5);
    std::cout << s.top() << " " << s.mini() << "\n";
    s.push(4);
    std::cout << s.top() << " " << s.mini() << "\n";
    s.push(10);
    s.push(13);
    while (s.top() != -1)
    {

        std::cout << s.top() << "-" << s.mini() << " ";
        s.pop();
    }

    return 0;
}