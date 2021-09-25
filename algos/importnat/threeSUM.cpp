#include <bits/stdc++.h>

using namespace std;

void TRIPLET(vector<int> v, int target)
{

    sort(v.begin(), v.end());
    int l, r;

    for (int i = 0; i < v.size() - 2; i++)
    {
        l = i + 1;
        r = v.size() - 1;
        while (l < r)
        {
            if (v[i] + v[l] + v[r] == target)
            {
                printf("Triplet is %d, %d, %d", v[i],
                       v[l], v[r]);
                return;
            }
            else if (v[i] + v[l] + v[r] < target)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }

    return;
}

int threeSumClosest(vector<int> &A, int B)
{
    int n = A.size();
    long long ans = (long long)(INT_MAX - abs(B));
    sort(A.begin(), A.end());
    long long minSum = (long long)A[0] + A[1] + A[2];
    long long maxSum = (long long)A[n - 1] + A[n - 2] + A[n - 3];

    if (B >= maxSum)
        return maxSum;
    if (B <= minSum)
        return minSum;

    int l, r;

    for (int i = 0; i < A.size() - 2; i++)
    {
        l = i + 1;
        r = A.size() - 1;
        while (l < r)
        {
            if (A[i] + A[l] + A[r] == B)
            {
                return B;
            }
            else if (A[i] + A[l] + A[r] < B)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
            int w = A[i] + A[l] + A[r];
            if (l < r && abs(w - abs(B)) < abs(ans - abs(B)))
            {
                ans = A[i] + A[l] + A[r];
            }
        }
    }

    return ans;
}

vector<vector<int>> threeSumZERO(vector<int> &A)
{
    vector<vector<int>> ans;

    sort(A.begin(), A.end());
    if (A[0] + A[1] + A[2] > 0)
        return ans;
    int l;
    for (int i = 0; i < A.size(); i++)
    {
        int s = i + 1;
        int e = A.size() - 1;
        l = INT_MAX;
        while (s < e)
        {
            int sum = A[i] + A[s] + A[e];
            if (sum == 0)
            {
                ans.push_back({A[i], A[s], A[e]});
                e--;
            }
            else if (sum > 0)
                e--;
            else
                s++;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        auto buff = ans[i];
        for (int j = i + 1; j < ans.size(); j++)
        {
            if (buff == ans[j])
            {
                ans.erase(ans.begin() + j);
            }
        }
    }

    return ans;
}
vector<vector<int>> threeSum(vector<int> &A)
{
    vector<vector<int>> ans;
    if (A.size() < 3)
        return ans;

    unordered_map<int, int> map;
    for (int x : A)
    {
        map[x]++;
    }
    sort(A.begin(), A.end());
    if (A[0] + A[1] + A[2] > 0)
        return ans;

    for (int i = 0; i < A.size(); i++)
    {

        int e = i + 1;
        while (e < A.size())
        {
            int diff = -1 * (A[i] + A[e]);

            if (map.find(diff) != map.end())
            {
                if ((diff == A[i] || (diff == A[e])) && map[diff] == 1)
                {
                    e++;
                    continue;
                }
                ans.push_back({A[i], diff, A[e]});
            }
            e++;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        auto buff = ans[i];
        for (int j = i + 1; j < ans.size(); j++)
        {
            if (buff == ans[j])
            {
                ans.erase(ans.begin() + j);
                j--;
            }
        }
    }

    return ans;
}
int main()
{

    vector<int> k;

    // k = {1, 4, 45, 6, 10, 8};
    // TRIPLET(k, 22);

    // k = {10, -6, 3, 4, -8, -5};
    // threeSumClosest(k, 3);
    // return 0;

    k = {1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3};
    k = {0, 0, 0, 0};
    k = {-1, 0, 1, 2, -1, -4};
    threeSumZERO(k);
    threeSum(k);
}
