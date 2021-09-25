#include <bits/stdc++.h>
using namespace std;

class myComp
{
public:
    bool operator()(int a, int b)
    {
        return a * a < b * b;
    }
};
int main()
{
    using namespace std;
    vector<int> v = {1, 5, 6, 3, 648, 3, 59, 3, 46, 34, 59, 6, 5, 26, 46, 56, 98, 22};

    sort(v.begin(), v.end(), [&](int a, int b)
         { return a < b; });
    printf("\n");
    for (auto x : v)
    {
        std::cout << x << " ";
    }

    sort(v.begin(), v.end(), [&](int a, int b)
         { return a > b; });
    printf("\n");
    for (auto x : v)
    {
        std::cout << x << " ";
    }

    priority_queue<int> maxHeap; //by default its max Heap
    maxHeap.push(3);
    maxHeap.push(2);
    std::cout << "\n"
              << maxHeap.top();

    printf("\n");
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(2);
    std::cout << "\n"
              << minHeap.top();

    auto cmp = [](int a, int b)
    {
        return a > b;
    };
    priority_queue<int, vector<int>, decltype(cmp)> custonHeap(cmp);
    custonHeap.push(5);
    custonHeap.push(-2);
    std::cout << "\n"
              << custonHeap.top();

    printf("\n");
    priority_queue<int, vector<int>, myComp> myHeap;
    myHeap.push(-5);
    myHeap.push(1);
    std::cout << myHeap.top();

    map<int, int> m;
    m.insert({0, 100});
    m.insert({1, 110});
    m.insert({2, 120});
    m.insert({3, 130});

    auto mapCMP = [](int a, int b)
    {
        return a > b;
    };
    map<int, char, decltype(mapCMP)> mm(mapCMP);
    mm.insert({0, 'a'});
    mm.insert({1, 'b'});
    mm.insert({3, 'd'});

    mm.insert({2, 'c'});
    mm.insert({3, 'f'});

    auto c = [](int a, int b)
    {
        return a > b;
    };
    set<int, decltype(c)> s(c);
    s.insert(1);
    s.insert(20);
    s.insert(15);
    queue<pair<int,int>>Q;
    
     map<int,map<int,vector<int>> > m;
    return 0;
}