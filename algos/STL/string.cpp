
#include <bits/stdc++.h>
using namespace std;

void printRecursion(string s)
{
    if (s.empty())
        return;
    printRecursion(s.substr(1));
    std::cout << s[0];
}

void PrintAllPermut(string str, string ans)
{
    if (str.empty())
    {
        std::cout << ans << " ";
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string left = str.substr(0, i);
        string right = str.substr(i + 1);
        string rest = left + right;
        string newAns = ans + ch;
        PrintAllPermut(rest, newAns);
    }
}

string removeDuplicateLetters(string s)
{
    unordered_map<char, int> map;
    int n = s.length();
    set<char> exist;
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        map[(char)s[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (st.empty())
        {
            st.push(ch);
            exist.insert(ch);
        }
        else
        {
            if (exist.find(ch) != exist.end())
            {
                continue;
            }
            if (st.top() < ch)
            {
                st.push(ch);
                exist.insert(ch);
                continue;
            }

            while (!st.empty() && st.top() > ch)
            {
                int lastOF = map.find(st.top())->second;
                if (lastOF > i)
                {
                    exist.erase(st.top());
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            st.push(ch);
            exist.insert(ch);
        }
    }

    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> partitionLabels(string s)
{
    int len = s.length();
    vector<int> first(26, -1);
    vector<int> last(26);
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if (first[c - 'a'] == -1)
        {
            first[c - 'a'] = i;
        }
    }
    for (int i = 0; i < len; i++)
    {
        last[s[i] - 'a'] = i;
    }

    vector<int> ans;
    for (int i = 0; i < len; i++)
    {
        int l = 0;
        char ch = s[i];
        l = last[ch - 'a'];
        for (int q = i; q <= l; q++)
        {
            if (last[s[q] - 'a'] > l)
            {
                l = last[s[q] - 'a'];
            }
        }

        ans.push_back(l - i + 1);

        i = l;
    }
    return ans;
}
int numTilePossibilities(string tiles)
{
    int n = tiles.length();
    vector<int> count(26);
    set<char> s;
    for (char c : tiles)
    {
        count[c - 'a']++;
        s.insert(c);
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
    }
    return ans;
}

string xray(string s)
{
    char ch = 'A';
    map<char, char> m;
    for (char &c : s)
    {
        auto x = m.find(c);
        if (x != m.end())
        {
            char g = x->second;
            c = g;
        }
        else
        {
            m[c] = ch;
            c = ch;
            ch++;
        }
    }
    return s;
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    string h = xray(pattern);
    vector<string> ans;
    for (auto word : words)
    {
        string w = xray(word);
        if (w == h)
        {
            ans.push_back(word);
        }
    }
    return ans;
}
int myAtoi(string s)
{
    string ans = "";
    int sign = 1;
    int isfound = false;
    for (char c : s)
    {
        if (c == ' ')
        {
            if (isfound)
            {
                break;
            }
        }
        else if (c == '+' || c == '-')
        {
            if (c == '-')
                sign = -1;
        }
        else if (isdigit(c))
        {
            isfound = true;
            ans += c;
        }
        else
        {
            break;
        }
    }
    if (ans.empty())
        return 0;
    int a;
    try
    {
        a = stoi(ans);
    }
    catch (const std::exception &e)
    {
        if (sign == '-')
            return INT_MIN;
        return INT_MAX;
    }

    return a;
}
int main()
{
    using namespace std;
    string s = "abcdefghijk";

    s = "   -42";
    myAtoi(s);
    int i = 3;
    std::cout << s.substr(i) << " " << s.substr(0, i) << "\n";
    std::cout << s.substr(s.length() - i) << " " << s.substr(i) << "\n";

    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string p = "abb";
    findAndReplacePattern(words, p);
    // reverse(s.begin(), s.end());
    // printRecursion(s);

    // std::cout << s;
    partitionLabels("eccbbbbdec");
    s = "ABCD";
    PrintAllPermut(s, "");
    s = "cbacdcbc";
    removeDuplicateLetters(s);
    return 0;
}