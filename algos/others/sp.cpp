#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<pair<int, int>> p;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        pair<int, int> xd = {nums[i], i};
        p.push_back(xd);
    }

    vector<int> ans;
    int i, j;
    i = 0;
    j = (int)nums.size() - 1;
    while (true)
    {
        if (p[i].first + p[j].first > target)
        {
            j--;
            continue;
        }
        else if (p[i].first + p[j].first < target)
        {
            i++;
            continue;
        }
        else if (p[i].first + p[j].first == target)
            ans.push_back(p[i].second);
        ans.push_back(p[j].second);
        break;
    }

    return ans;
}
int main()
{

    vector<int> a = {2, 7, 11, 15};
    vector<int> b;
    b = twoSum(a, 9);
    for (auto x : b)
        cout << x << " ";
    return 0;
}
