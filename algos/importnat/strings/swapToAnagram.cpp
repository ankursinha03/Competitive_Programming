#include <bits/stdc++.h>
using namespace std;

int swapToAnagram(string s1, string s2)
{
    const int n = s1.length();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (s1[i] != s2[j])
        {
            j++;
        }
        while (i < j)
        {
            swap(s2[j - 1], s2[j]);
            count++;
            j--;
        }
    }
    return count;
}

int main()
{
    using namespace std;
    string s1 = "abcfdegji";
    string s2 = "fjiacbdge";
    std::cout << swapToAnagram(s1, s2);
    return 0;
}