#include <bits/stdc++.h>
using namespace std;
void add(string &s)
{
    reverse(s.begin(), s.end());
    int c = 1;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int a = ch - '0';
        int sum = a + c;
        if (sum < 10)
        {
            s[i] = sum + '0';
            c = 0;
        }
        else
        {
            s[i] = '0';
            c = 1;
        }
    }
    if (c == 1)
        s.push_back('1');
    reverse(s.begin(), s.end());
}

string solve(string A)
{

    while (1)
    {
        add(A);
        std::cout << A << "\n";
        int s = 0;
        bool flag = 1;
        int e = A.length() - 1;
        while (s <= e)
        {
            if (A[s] != A[e])
            {
                flag = 0;
                break;
            }
            s++;
            e--;
        }
        if (flag)
            return A;
    }
    return "";
}

int main()
{
    using namespace std;
    std::cout << solve("2168576189279543123341");
    return 0;
}