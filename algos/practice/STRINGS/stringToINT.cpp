#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int> &a, const vector<int> &b)
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    if (m > n)
    {
        return checkInclusion(s2, s1);
    }
    vector<int> h1(26);
    for (char c : s1)
    {
        h1[c - 'a']++;
    }
    vector<int> h2(26);
    for (int i = 0; i < m; i++)
    {
        h2[s2[i] - 'a']++;
    }

    int s = 0;
    while (s <= n - m)
    {
        if (check(h1, h2))
            return true;
        else
        {
            h2[s2[s] - 'a']--;
            s++;
            if (s + m - 1 >= s2.length())
                break;
            h2[s2[s + m - 1] - 'a']++;
        }
    }
    return false;
}
int main()
{
    using namespace std;
    std::cout << checkInclusion("ab", "eidboaoo");
    int r1, i1, r2, i2;
    string num1 = "78+-76i";
    string num2 = "-86+72i";

    auto i = num1.find('+');
    string a1(num1.begin(), num1.begin() + i);
    string a2(num1.begin() + i + 1, prev(num1.end()));
    r1 = stoi(a1);
    i1 = stoi(a2);

    string b1(num2.begin(), num2.begin() + i);
    string b2(num2.begin() + i + 1, prev(num2.end()));
    r2 = stoi(b1);
    i2 = stoi(b2);
    int R = r1 * r2 - i1 * i2;
    int I = i1 * r2 + r1 * i2;
    string ans = to_string(R) + "+" + to_string(I);
    int s = 55;
    try
    {
        s = stoi("i75412"); /* code */
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    float f = stof("7.256");
    std::cout << f;
    printf("\n");
    std::cout << s;
    return 0;
}