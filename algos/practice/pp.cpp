#include <bits/stdc++.h>
using namespace std;

string mostCommonWord(string paragraph, vector<string> &banned)
{

    unordered_map<string, int> mp;
    int i, j;
    i = 0;
    j = 0;
    while (j < paragraph.size())
    {
        i = j;
        while (paragraph[j] != ' ' && paragraph[j] != ',' && paragraph[j] != ';' && paragraph[j] != '.')
        {
            j++;
        }
        if (!paragraph.substr(i, j - i).empty())
        {
            string k = paragraph.substr(i, j - i);

            transform(k.begin(), k.end(), k.begin(), ::tolower);
            mp[k]++;
        }

        i = j + 1;
        j++;
    }

    set<string> ban;
    for (auto s : banned)
    {
        ban.insert(s);
    }
    for (auto s : ban)
    {
        if (mp.find(s) != mp.end())
            mp.erase(s);
    }
    int k = INT_MIN;
    for (auto p : mp)
    {
        k = max(k, p.second);
    }
    for (auto p : mp)
    {
        if (p.second == k)
            return p.first;
    }
    return "";
}
int main()
{
    using namespace std;

    vector<string> v = {"hit"};

    mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", v);
    return 0;
}