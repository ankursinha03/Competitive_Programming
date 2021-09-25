#include <bits/stdc++.h>
using namespace std;

int minimumSwap(string s)
{
    const int n = s.length();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int left = i;
        int right = n - left - 1;
        // if (left == right)
        //     break;
        if (s[left] == s[right])
            continue;
        while (left < right)
        {
            if (s[left] == s[right])
                break;
            right--;
        }

        // return -1;
        for (int j = right; j < n - left - 1; j++)
        {
            if (j == n / 2 && left == right)
                break;
            swap(s[j], s[j + 1]);
            count++;
        }
    }

    return count;
}
int main()
{
    using namespace std;
    string s = "aaaazz";
    std::cout << minimumSwap(s);
    return 0;
}