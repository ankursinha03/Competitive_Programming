#include <bits/stdc++.h>
using namespace std;

bool isScramble(string a, string b)
{
    if (a.length() != b.length())
        return false;
    if (a.length() == 0 && b.length() == 0)
        return true;
    if (a == b)
        return true;
    int n = a.length();
    for (int i = 1; i < a.length(); i++)
    {
        string aL = a.substr(0, i);
        string aU = a.substr(i);
        string bL = b.substr(0, i);
        string bU = b.substr(i);
        if ((isScramble(a.substr(0, i), b.substr(n - i, i)) && isScramble(a.substr(i, n - 1), b.substr(0, n - i))) || (isScramble(a.substr(0, i), b.substr(0, i)) && isScramble(a.substr(i), b.substr(i))))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    using namespace std;
    std::cout << isScramble("abb", "bba");
    return 0;
}

class Solution
{

    bool solve(string a, string b, map<pair<string, string>, bool> &m)
    {
        if (a.length() != b.length())
            return false;

        if (a.length() == 0 && b.length() == 0)
        {
            if (m.find({a, b}) == m.end())
            {
                m[{a, b}] = 1;
            }
            return true;
        }
        if (m.find({a, b}) != m.end())
        {
            return m[{a, b}];
        }

        if (a == b)
        {
            if (m.find({a, b}) == m.end())
            {
                m[{a, b}] = 1;
            }
            return true;
        }

        for (int i = 1; i < a.length(); i++)
        {
            string aL = a.substr(0, i);
            string aU = a.substr(i);
            string bL = b.substr(0, i);
            string bU = b.substr(i);
            bool p, q, r, s;
            if (m.find({aL, bL}) != m.end())
            {
                p = m[{aL, bL}];
            }
            else
            {
                p = solve(aL, bL, m);
            }
            if (m.find({aU, bU}) != m.end())
            {
                q = m[{aU, bU}];
            }
            else
            {
                q = solve(aU, bU, m);
            }
            if (p && q)
            {
                m[{a, b}] = 1;
                return m[{a, b}];
            }

            if (m.find({aL, bU}) != m.end())
            {
                r = m[{aL, bU}];
            }
            else
            {
                r = solve(aL, bU, m);
            }
            if (m.find({aU, bL}) != m.end())
            {
                s = m[{aU, bL}];
            }
            else
            {
                s = solve(aU, bL, m);
            }

            if (r && s)
            {
                m[{a, b}] = 1;
                return m[{a, b}];
            }
        }
        m[{a, b}] = 0;
        return m[{a, b}];
    }

public:
    bool isScramble(string a, string b)
    {
        map<pair<string, string>, bool> m;
        return solve(a, b, m);
    }
};