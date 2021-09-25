#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool check(vector<int> &nums)
{
    if (nums.size() == 1)
        return true;
    int c = 0;
    for (int i = 0; i <= nums.size() - 2; i++)
        if (nums[i] > nums[i + 1])
            c++;
    if (c == 0)
        return true;
    if (c == 1 && nums[0] >= nums[nums.size() - 1])
        return true;
    return false;
}
vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> ans;
    string s;
    if (nums.empty())
        return ans;
    if (nums.size() == 1)
    {
        ans.push_back(to_string(nums[0]));
        return ans;
    }
    int start = 0;
    int end = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - 1 == nums[i - 1])
        {
            end++;
            if (end == nums.size() - 1)
            {
                if (end != start)
                {
                    s = to_string(nums[start]) + "->" + to_string(nums[end]);
                    ans.push_back(s);
                }
                else
                {
                    s = to_string(nums[start]);
                    ans.push_back(s);
                }
            }
        }

        else
        {
            if (end != start)
            {
                s = to_string(nums[start]) + "->" + to_string(nums[end]);
                ans.push_back(s);
            }
            else
            {
                s = to_string(nums[start]);
                ans.push_back(s);
            }
            end++;
            start = end;
        }
    }
    if (start == end && end == nums.size() - 1)
    {
        s = to_string(nums[end]);
        ans.push_back(s);
    }
    return ans;
}

;
int main()
{
    using namespace std;

    vector<int> v = {1, 2, 3, 4, 5, 7, 12, 13, 55};

    vector<string> s;
    s = summaryRanges(v);
    for (auto x : s)
        std::cout << x << endl;
    return 0;
}
