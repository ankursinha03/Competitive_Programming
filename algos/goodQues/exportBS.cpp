#include <bits/stdc++.h>
using namespace std;
unordered_map<string,vector<pair<int, string>>> m;
bool can(vector<int> &v, int days, int ans)
{
    int z = 0;
    for (int x : v)
    {
        z += x;
        if (z > ans)
        {
            z = x;
            days--;
            if (days < 0)
                return false;
        }
    }
    days--;
    if (days < 0)
        return false;
    return true;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int s = *max_element(weights.begin(), weights.end());
    int e=0;
        for(int x: weights) e+=x;
    int ans = INT_MAX;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (can(weights, days, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}
int main()
{
    using namespace std;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    shipWithinDays(v, 5);
    return 0;
}