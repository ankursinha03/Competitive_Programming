#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &v, int target)
{
    const int n = v.size();
    int s = 0;
    int e = n - 1;
    if (n == 1)
    {
        return (v[0] == target) ? 0 : -1;
    }
    while (s < e)
    {
        if (v[s] == target)
            return s;
        if (v[e] == target)
            return e;
        int mid = s + (e - s) / 2;
        if (v[mid] == target)
            return mid;
        if (v[s] > v[e])
        {
            if (v[s] > target)
            {
                if (v[mid] > e)
                {
                    s = mid + 1;
                }
                else
                {
                    if (v[mid] > target)
                        e = mid - 1;
                    else
                        s = mid + 1;
                }
            }
            else
            {
                if (v[mid] < e)
                {
                    e = mid - 1;
                }
                else
                {
                    if (v[mid] > target)
                    {
                        e = mid - 1;
                    }
                    else
                    {
                        s = mid + 1;
                    }
                }
            }
        }
        else
        {
            if (v[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
    }
    return -1;
}
int findMax(vector<int> &v)
{
    int ans = -1;
    int max = INT_MIN;

    int n = v.size();
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (v[s] > v[e])
        {
            if (v[mid] > v[s])
            {
                if (v[mid] > max)
                {
                    max = v[mid];
                    ans = mid;
                }
                s = mid + 1;
            }
            else
            {
                if (v[mid] > max)
                {
                    max = v[mid];
                    ans = mid;
                }
                e = mid - 1;
            }
        }
        else
        {
            if (v[mid] > max)
            {
                max = v[mid];
                ans = mid;
                s = mid + 1;
            }
        }
        if (v[mid] > max)
        {
            max = v[mid];
            ans = mid;
        }
    }
    if (v[s] > max)
    {
        max = v[s];
        ans = s;
    }

    return ans;
}
int main()
{
    using namespace std;
    vector<int> v = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    findMax(v);
    return 0;
}