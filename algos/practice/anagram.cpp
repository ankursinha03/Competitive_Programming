#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    //char arr: 26 length
    //and if the are anagrams they will have same arr
    map<vector<int>, vector<string>> mp;

    vector<int> temp;
    for (auto str : strs)
    {
        temp.clear();
        for (auto c : str)
        {
            temp[c - 'a']++;
        }
        if (mp.find(temp) != mp.end())
            mp[temp].push_back(str);
        else
            mp[temp] = {str};
    }

    vector<vector<string>> ans;

    for (auto x : mp)
    {
        ans.push_back(x.second);
    }

    return ans;
}

int main()
{
    using namespace std;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);
    return 0;
}