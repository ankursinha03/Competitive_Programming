#include <bits/stdc++.h>
using namespace std;

int findMaximumXOR(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;

    auto mx = max_element(nums.begin(), nums.end());
    int max_base = floor(log2(*mx));

    vector<vector<int>> nxt(1, vector<int>(2));

    int N = 0;

    for (int n : nums)
    {

        int node = 0;
        for (int i = max_base; i >= 0; i--)
        {
            bool pos = n & (1 << i);
            if (nxt[node][pos] == 0)
            {
                nxt.push_back(vector<int>(2));
                nxt[node][pos] = ++N;
            }
            node = nxt[node][pos];
        }
    }
    //tree is built

    int ans = 0;

    for (int n : nums)
    {
        int xord = 0;
        N = 0;
        int buff = 0;
        int node = 0;
        for (int i = max_base; i >= 0; i--)
        {
            bool val = n & (1 << i);
            if (nxt[node][!val] != 0)
            {
                buff = buff | ((val ^ !val) << i);
                node = nxt[node][!val];
            }
            else if (nxt[node][val] != 0)
            {
                buff = buff | ((val ^ val) << i);
                node = nxt[node][val];
            }
        }
        ans = max(ans, buff);
    }

    return ans;
}
int main()
{
    using namespace std;
    vector<int> v = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    std::cout << findMaximumXOR(v);
    return 0;
}