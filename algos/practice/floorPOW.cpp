#include <bits/stdc++.h>
using namespace std;
bool isPowerOfThree(int n)
{
    if (n == 0)
        return 0;
    if (n <= 0)
        return 0;

    double x = log10(n) / log10(3);
    cout << (double)x;
    if (floor((double)x) == x)
        return 1;
    cout << floor((double)x) << x;
    return 0;
}

int main()
{
    using namespace std;
    std::cout << isPowerOfThree(243);
    return 0;
}