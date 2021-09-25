#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int n, map<string, pair<int, int>> items, int sortParameter, int sortOrder, int itemPerPage, int pageNumber)
{

    vector<pair<string, pair<int, int>>> v;
    for (auto i : items)
    {
        v.push_back(i);
    }
    if (sortOrder == 0)
    {
        //accending
        if (sortParameter == 0)
        {
            sort(v.begin(), v.end(), [](pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
                 { return a.first < b.first; });
        }
        else if (sortParameter == 1)
        {
            sort(v.begin(), v.end(), [](pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
                 { return a.second.first < b.second.first; });
        }
        else
        {
            sort(v.begin(), v.end(), [](pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
                 { return a.second.second < b.second.second; });
        }
    }
    else
    {
        //deceding
        if (sortParameter == 0)
        {
            sort(v.begin(), v.end(), [](pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
                 { return a.first > b.first; });
        }
        else if (sortParameter == 1)
        {
            sort(v.begin(), v.end(), [](pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
                 { return a.second.first > b.second.first; });
        }
        else
        {
            sort(v.begin(), v.end(), [](pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
                 { return a.second.second > b.second.second; });
        }
    }
    int mypage = 0;
    int i = 0;
    int temp;
    vector<string> ans;
    while (mypage < pageNumber)
    {
        temp = itemPerPage;
        while (temp--)
        {
            i++;
        }
        mypage++;
    }

    if (mypage == pageNumber)
    {
        for (int k = i; k < v.size() && k < i + itemPerPage; k++)
        {
            ans.push_back(v[i].first);
        }
    }

    return ans;
}
int main()
{
    using namespace std;
    vector<long> v;
    // v = {1, 2, 3, 10};
    // std::cout << solve(v, 4);
    // vector<vector<int>> queries = {{3, 4}, {6, 5}};
    // numberOfWays(queries);
    map<string, pair<int, int>> items;
    items.insert({"item1", {10, 15}});
    items.insert({"item2", {3, 4}});
    items.insert({"item3", {17, 8}});
    solve(3, items, 1, 0, 2, 1);
    return 0;
}
