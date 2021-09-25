#include <bits/stdc++.h>
using namespace std;

int main()
{
    using namespace std;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> v;
    v = {8, 2, 15, 13, 13, 2, 1, 6, 1, 5, 14, 12, 2, 7, 5, 14, 15, 14, 13, 6};
    int k = 2;
    8 2 7 15 10 13 11 11 10 14 4 2 6 5 3 11 12 5 1 3 
    for (int j = 0; j < v.size(); j++)
    {
        cout << v[j] << " ";

        minHeap.push(v[j]);
        if (minHeap.size() > k)
            minHeap.pop();
    }
    cout << "\n";

    minHeap.push(5);
    minHeap.push(15);
    minHeap.push(51);
    minHeap.push(55);
    minHeap.push(65);
    minHeap.push(5);
    minHeap.push(58);
    //minHeap.v = {70, 56, 94, 34, 22, 66, 4, 1, 2, 5};
    make_heap(v.begin(), v.end());
    std::cout << "MAX HEAP: " << v.front();
    //popping the max element
    pop_heap(v.begin(), v.end());
    std::cout << "head is: " << v.front() << " back is: " << v.back();
    v.pop_back();
    v.push_back(100);
    push_heap(v.begin(), v.end());
    std::cout << "\nWe have our new head as: " << v.front();
    pop_heap(v.begin(), v.end());

    printf("\n");
    for (int x : v)
        std::cout << x << " ";
    return 0;
}