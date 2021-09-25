#include <iostream>
#include <deque>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int> Dq;
    Dq.push_back(55);
    Dq.push_back(88);
    Dq.push_front(101);

    Dq.front() -= 1;
    Dq.back() += 2;

    Dq.push_back(55);
    Dq.push_back(88);
    Dq.push_front(101);

    for (int x : Dq)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    Dq.pop_back();
    Dq.pop_front();

    for (int x : Dq)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << Dq.at(2);
    std::cout << std::endl;
    std::cout << Dq[2];
    std::cout << std::endl;

    Dq.resize(5);
    Dq.resize(8, 12);
    std::cout << std::endl;
    for (int x : Dq)
    {
        std::cout << x << " ";
    }
    return 0;
}
