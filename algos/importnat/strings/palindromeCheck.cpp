#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string A)
{
    const int n = A.length();
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        if (!isalnum(A[s]))
        {
            s++;
        }
        if (!isalnum(A[e]))
        {
            e--;
        }
        char p = tolower(A[s]);
        char q = tolower(A[e]);
        if (p == q)
        {
            s++;
            e--;
        }
        else
        {
            cout << p << "-" << q << " ";
            return 0;
        }
    }
    return 1;
}
string countAndSay(int A)
{
    if (A == 1)
        return "1";

    string k = countAndSay(A - 1);
    string res = "";
    for (int i = 0; i < k.size(); i++)
    {
        int j = i;
        int count = 0;
        while (j < k.size() && k[i] == k[j])
        {
            count++;
            j++;
        }
        res += to_string(count) + k[i];
        j--;
        i = j;
    }
    return res;
}

string solve(string A, int B)
{
    int n = A.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        bool flag = 0;
        for (int k = i; k < i + B - 1; k++)
        {
            if (k == n)
                break;
            if (A[k] != A[k + 1])
                flag = 1;
        }
        if (!flag)
        {
            i = i + B - 1;
        }
        else
        {
            ans += A[i];
        }
    }

    return ans;
}
int main()
{
    using namespace std;
    solve("aabcd", 2);
    countAndSay(2);
    isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}