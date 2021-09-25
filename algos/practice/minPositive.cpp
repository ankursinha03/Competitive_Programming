#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int k = 0;
    long long sum = 0;
    int mini = INT_MAX;
    int numOfOnes = 0;
    for (int n : nums)
    {
        if (n > 0)
        {
            if (n == 1)
            {
                numOfOnes++;
            }
            k++;
            sum += (long long)n;
            mini = min(mini, n);
        }
    }
    if (mini > 1)
        return 1;
    if (numOfOnes == nums.size())
        return 2;

    long long expected = (k + 1) * (k + 2) * 0.5;
    int ans = expected - sum;
    return ans;
}
string removeDuplicates(string s)
{
    string a;
    int i = 0;

    while (s[i])
    {
        if (s[i] != s[i + 1])
        {
            a += s[i];
            i++;
        }
        if (s[i] && s[i + 1] == s[i])
        {
            while (s[i] && s[i + 1] == s[i])
                i++;
            i++;
        }
    }
    if (a.empty())
        return a;
    i = 0;
    string ans;
    while (a[i])
    {
        if (a[i] != a[i + 1])
        {
            ans += a[i];
            i++;
        }
        if (a[i] && a[i + 1] == a[i])
        {
            while (a[i] && a[i + 1] == a[i])
                i++;
            i++;
        }
    }

    return ans;
}
int main()
{
    using namespace std;
    vector<int> v = {1, 1};
    removeDuplicates("aaaaaaaa");
    firstMissingPositive(v);
    return 0;
}