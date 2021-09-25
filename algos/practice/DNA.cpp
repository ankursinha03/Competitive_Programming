#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> res;
    if (s.size() < 11)
        return res;
    int i = 0;
    string t = "";
    while (i < 10)
        t.push_back(s[i++]);
    unordered_map<string, int> mp;
    mp[t]++;
    while (i < s.size())
    {
        t = t.substr(1) + s[i++];
        mp[t]++;
    }
    for (auto i : mp)
    {
        if (i.second > 1)
            res.push_back(i.first);
    }
    return res;
}

int main()
{
    using namespace std;
    string s = "AAAAAAAAAAA";
    findRepeatedDnaSequences(s);

    return 0;
}