#include <bits/stdc++.h>
using namespace std;
unsigned int reverse(unsigned int A)
{

    unsigned int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        unsigned int k = (1 << (31 - i));
        if (A & (1 << i))
        {
            ans = ans + k;
        }
    }
    return ans;
}
bool isPrime(int n)
{
    if (n == 2 || n == 3)
        return true;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solve(int A)
{
    int ans = 0;
    int k = 0;
    int t = A;
    if (A == 0)
        return 0;
    if (A == 1 || A == 2)
        return 1;
    t = A;

    int x = log(A) / log(2);
    ans = pow(2, x - 1) * (x);

    ans += (A - pow(2, x) + 1);
    ans += solve(A - pow(2, x) + 1);
    return ans % 1000000007;
}

int main()
{
    using namespace std;

    // int A = 52;
    // reverse(3);
    // for (int i = 8; i >= 0; i--)
    // {
    //     if (((1 << i) & A) != 0)
    //         std::cout << 1;
    //     else
    //         std::cout << 0;
    // }
    solve(10);
    int x = 5;
    x |= 1 << 1;
    std::cout << x;
    printf("\n");
    x &= ~(1 << 2);
    std::cout << x;

    int num = 5;
    int k = 0;
    int n = num;
    while (n != 0)
    {
        k++;
        n /= 2;
    }
    for (int i = 0; i < k; i++)
    {
        num ^= 1 << i;
    }
    std::cout << num;
    int left, right;
    left = 6;
    right = 10;
    int ans = 0;
    int count;
    for (int i = left; i <= right; i++)
    {
        count = 0;
        for (int j = 0; j < 32; j++)
        {
            if (i & (1 << j))
                count++;
        }
        if (isPrime(count))
            ans++;
    }
    bool prev;
    int nn = 7;
    prev = nn & (1 << 0);
    return 0;
}