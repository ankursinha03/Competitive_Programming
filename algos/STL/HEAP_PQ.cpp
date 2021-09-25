#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    // priority_queue<int> pq(nums.begin(), nums.end());
    unordered_map<int, int> m;
    for (int x : nums)
    {
        m[x]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto p : m)
    {

        minHeap.push({p.second, p.first});
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    vector<int> ans;
    while (!minHeap.empty())
    {
        auto p = minHeap.top();
        ans.push_back(p.second);
        minHeap.pop();
    }
    return ans;
}
int main()
{
    using namespace std;
    vector<int> v1 = {1, 1, 1, 2, 2, 3};
    topKFrequent(v1, 2);
    vector<int> v = {4, 5, 9, 65, 6496, 6, 53, 6, 46, 49, 45, 59, 46, 46, 64, 6, 76, 96, 16, 4, 46, 10};

    priority_queue<int> pq1(v.begin(), v.end());

    while (!pq1.empty())
    {
        std::cout << pq1.top() << " ";
        pq1.pop();
    }
    auto cmp = [](int a, int b)
    { return a > b; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(v.begin(), v.end(), cmp);
    printf("\n");
    while (!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    //finding kth smallest
    //and kth largest

    vector<int> vt = {7, 10, 4, 3, 20, 15};
    int k = 3;
    priority_queue<int> maxHeap;
    for (auto x : vt)
    {
        maxHeap.push(x);
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (auto x : vt)
    {
        minHeap.push(x);
        if (minHeap.size() > k)
            minHeap.pop();
    }

    printf("\n");
    printf("\n");
    std::cout << " Kth smallest element: " << maxHeap.top() << "\nKth largest element: " << minHeap.top();
    return 0;
}