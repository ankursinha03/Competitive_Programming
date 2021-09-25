#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 256

int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}

void populateAndIncreaseCount(int *count, char *str)
{
}

void updatecount(int *count, char ch)
{

    for (int i = ch; i < MAX_CHAR; ++i)
        --count[i];
}

int findRank(char *str)
{
    int len = strlen(str);
    int mul = fact(len);
    int rank = 1, i;

    int count[MAX_CHAR] = {0};
    int w;

    for (w = 0; str[w]; ++w)
        ++count[str[w]];

    for (w = 1; w < MAX_CHAR; ++w)
        count[w] += count[w - 1];

    for (i = 0; i < len; ++i)
    {
        mul /= len - i;
        rank += count[str[i] - 1] * mul;
        // updatecount(count, str[i]);
        for (int k = str[i]; k < MAX_CHAR; ++k)
            --count[k];
    }

    return rank;
}

int RANK(string s)
{
    int l = s.length();
    int mul = fact(l);
    int ans = 1;
    vector<int> aux(256);

    for (int i = 0; i < l; i++)
    {
        aux[s[i]]++;
    }

    for (int i = 1; i < 256; i++)
    {
        aux[i] += aux[i - 1];
    }

    for (int i = 0; i < l; i++)
    {
        mul /= l - i;
        ans += aux[s[i] - 1] * mul;
        for (int k = s[i]; k < 256; k++)
        {
            --aux[k];
        }
    }
    return ans;
}
string runLenEnco(string s)
{
    string ans = "";
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i != s.length() - 1 && s[i] == s[i + 1])
        {
            count++;
        }
        else
        {
            if (i == s.length() - 1)
            {
                if (!s[i] == s[i - 1])
                {
                    ans += s[i] + to_string(1);
                    break;
                }
            }
            ans += s[i] + to_string(count + 1);
            count = 0;
        }
    }
    return ans;
}
bool isSubsequence(string s, string t)
{
    int a, b;
    a = b = 0;
    while (b < t.length() && a < t.length())
    {
        if (s[b] == t[a])
        {
            a++;
            b++;
        }
        else
        {
            a++;
        }
    }
    if (b != t.length())
        return false;
    return true;
}

string reverseWords(string s)
{
    int S = 0;
    const char ch = ' ';
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == ch && s[i] == s[i + 1])
        {
            s.erase(s.begin() + i);
            i--;
        }
    }
    n = s.length();
    if (s[0] == ch)
        s.erase(s.begin());
    n = s.length();
    if (s[n - 1] == ch)
        s.erase(prev(s.end()));
    n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ch)
        {
            reverse(s.begin() + S, s.begin() + i);
            S = i + 1;
        }
        if (i == n - 1)
        {
            reverse(s.begin() + S, s.end());
        }
    }
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    // char str[] = "cba";
    // cout << findRank(str) << " " << RANK("cba");
    // printf("\n");
    // std::cout << runLenEnco("wwwwaaadexxxxxxccc");
    // int a = 97;
    // char ch = a ^ 32;
    // std::cout << ch;
    // std::cout << isSubsequence("abc", "ahbgdc");
    reverseWords("  Bob    Loves  Alice   ");
    return 0;
}