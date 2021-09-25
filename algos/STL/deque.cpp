#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    using namespace std;
    vector<int> v(10, 2);

    deque<int> dq;
    for (int i = 0; i < 10; i++)
    {
        dq.push_back(i);
    }
    for (auto x : v)
        std::cout << x << " ";
    printf("\n");
    for (auto x : dq)
        std::cout << x << " ";

    return 0;
}