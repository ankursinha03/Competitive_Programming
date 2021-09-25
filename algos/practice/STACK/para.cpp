#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s)
{
    vector<int> aux(s.length());
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            aux[i] = 1;
        else
            aux[i] = -1;
    }
    int z = 1;
    for (int i = 1; i < s.length(); i++)
    {
        aux[i] += aux[i - 1];
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s.at(i);
        if (aux[i] == 1 && ch == '(')
        {
            continue;
        }
        if (aux[i] == 0)
            continue;
        ans += s[i];
    }
    return ans;
}

int main()
{
    using namespace std;
    string k =
        "((()())(()()))";
    removeOuterParentheses(k);
    return 0;
}