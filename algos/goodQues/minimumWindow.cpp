#include <bits/stdc++.h>
using namespace std;
bool equal(int a[], int b[])
{
    for (int i = 0; i < 256; i++)
    {
        if (b[i] == 0)
            continue;
        if (a[i] < b[i])
            return 0;
    }
    return 1;
}
string minWindow(string str, string t)
{
    const int n = str.length();
    if (n < t.size())
        return "";
    int freqT[256];
    memset(freqT, 0, sizeof(freqT));

    for (char ch : t)
    {
        freqT[ch]++;
    }
    int freq[256];
    memset(freq, 0, sizeof(freq));
    int s = 0;
    int e = 0;
    for (e; e < n; e++)
    {
        freq[str[e]]++;
        if (equal(freq, freqT))
            break;
    }
    pair<int, int> ans;
    ans = {s, e};
    while (e < n)
    {
        while (s < n and equal(freq, freqT))
        {
            if (ans.second - ans.first > e - s)
            {
                ans = {s, e};
            }
            freq[str[s]]--;
            s++;
        }
        while (e < n and !equal(freq, freqT))
        {
            e++;
            freq[str[e]]++;
        }
        // if (equal(freq, freqT) and ans.second - ans.first > e - s)
        // {
        //     ans = {s, e};
        // }
    }
    if (ans.second == n and ans.first == 0)
    {
        if (str == t)
            return str;
        return "";
    }
    return str.substr(ans.first, ans.second - ans.first + 1);
}

int main()
{
    using namespace std;
    std::cout << minWindow("a", "b");
    return 0;
}