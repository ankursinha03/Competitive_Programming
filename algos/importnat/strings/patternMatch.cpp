#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string s)
{
    int n = s.length();
    vector<int> LPS(n);
    LPS[0] = 0;
    int len = 0;
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                LPS[i] = 0;
                i++;
            }
            else
            {
                len = LPS[len - 1];
            }
        }
    }

    return LPS;
}

void KMP(string &T, string &P)
{
    int n = T.length();
    int m = P.length();
    vector<int> Lps;
    Lps = LPS(P);
    int i = 0, j = 0;
    while (i < n)
    {
        if (P[j] == T[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            std::cout << i - j << " ";
            j = Lps[j - 1];
        }
        else if (i < n && P[j] != T[i])
        {
            if (j == 0)
                i++;
            else
                j = Lps[j - 1];
        }
    }
}

int lengthOfLongestSubstring(string s)
{
    vector<bool> present(256);
    int i = 0;
    int j = 0;
    int n = s.length();
    int ans = INT_MIN;
    if (s.empty())
        return 0;
    while (j < n)
    {

        if (!present[s[j]])
        {

            present[s[j]] = true;
            j++;
            if (j == n)
            {
                ans = max(ans, j - i);
            }
        }
        else
        {
            ans = max(ans, j - i);
            while (present[s[j]])
            {
                present[s[i]] = 0;
                i++;
            }
        }
    }
    return ans;
}
bool check(const vector<int> &SSF, const vector<bool> &contains)
{
    for (int i = 0; i < 256; i++)
    {
        if (contains[i] && !SSF[i])
        {
            return false;
        }
    }
    return true;
}
string smallestWindow(string s, string p)
{
    string ans;
    int size = INT_MAX;
    vector<bool> contains(256);
    for (char c : p)
    {
        contains[c] = 1;
    }
    int i = 0;
    int j = 0;

    int n = s.size();
    vector<int> SeenSoFar(256);
    SeenSoFar[s[0]]++;
    while (j <= n)
    {
        if (check(SeenSoFar, contains))
        {
            while (check(SeenSoFar, contains))
            {
                SeenSoFar[s[i]]--;
                i++;
            }
            string temp(s.begin() + i - 1, s.begin() + j + 1);
            if (temp.size() < size)
            {

                ans.clear();
                ans = temp;
                size = ans.size();
            }
        }
        j++;
        if (j < n)
            SeenSoFar[s[j]]++;
    }
    if (size == INT_MAX)
        return "-1";
    return ans;
}
int main()
{
    using namespace std;
    vector<int> v;

    std::cout << smallestWindow("hasjkhflaskdf", "sdlkjfshd");
    printf("\n");
    lengthOfLongestSubstring(" ");
    v = LPS("banana");
    for (auto x : v)
        std::cout << x << "-";
    printf("\n");
    string T = "abcbabca";
    string P = "ab";
    KMP(T, P);

    return 0;
}