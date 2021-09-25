#include <iostream>
#include <stack>
#include <stdio.h>

int main()
{
    using namespace std;
    stack<int> s;
    s.push(30);
    s.push(12);
    std::cout << s.top(); //Returns a reference to the top element in the stack.
    s.top() += 10;
    printf("\n");
    std::cout << s.top();
    s.pop();
    printf("\n");
    std::cout << s.top();
    printf("\n");
    printf("\n");
    s.emplace(33);
    s.push(15);
    s.push(15);
    s.push(153);
    s.push(152);
    s.push(15);
    s.push(115);
    printf("\n");
    std::cout << "The size of the stack is " << s.size();
    printf("\n");
    while (!s.empty())
    {
        std::cout << s.top();
        printf("\n");
        s.pop();
    }

    return 0;
}
