#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void reverseString(string &s)
{
    for (int i = 0; i < s.length() / 2; i++)
    {
        swap(s[i], s[s.length() - 1 - i]);
    }
}
void revRecursion(string s)
{
    if (s.length() == 0)
        return;
    revRecursion(s.substr(1));
    std::cout << s[0];
}
void PrintAllPermut(string s, string ans)
{
    if (s.length() == 0)
        std::cout << ans << " ";
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0, i);
        string right_substr = s.substr(i + 1);
        string rest = left_substr + right_substr;
        PrintAllPermut(rest, ans + ch);
    }
}
int main()
{
    using namespace std;
    string s = "abc";
    reverseString(s);
    std::cout << s;
    printf("\n");
    revRecursion(s);
    printf("\n");
    reverseString(s);
    PrintAllPermut(s, "");
    return 0;
}