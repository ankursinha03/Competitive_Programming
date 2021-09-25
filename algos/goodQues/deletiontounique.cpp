#include <bits/stdc++.h>
using namespace std;

bool unique(vector<int> &v)
{
    int sz = v.size();
    sort(v.begin(), v.end());
    for (int i = sz - 2; i >= 0; i--)
    {
        if (v[i] == 0)
            continue;
        if (v[i] == v[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int minDeletions(string s)
{
    vector<int> count(26);

    for (char c : s)
    {
        count[c - 'a']++;
    }

    vector<int> freq;
    for (int c : count)
    {
        if (c)
            freq.push_back(c);
    }
    int ans = 0;

    while (!unique(freq))
    {

        int sz = freq.size();

        for (int i = sz - 2; i >= 0; i--)
        {
            {
                if (freq[i] == freq[i + 1])
                {
                    freq[i]--;
                    ans++;
                    break;
                }
            }
        }
    }
    return ans;
}

int main()
{
    using namespace std;
    minDeletions("fhwgjfjdnjinvjksvjisdvjisdnjvhsujvndskvuegkenfjebgujenvhbdjniewjfiejfijijijijijijivdjvndjvnjdn");
    return 0;
}