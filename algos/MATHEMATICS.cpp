#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++) //O(N^1/2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
vector<int> primesLessThanN(int n) //sieve theorem
{
    vector<bool> prime(n + 1, 1);
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i < n + 1; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = 2; i * j <= n; j++)
            {
                prime[i * j] = 0;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < n + 1; i++)
    {
        if (prime[i])
            ans.push_back(i);
    }
    return ans;
}
vector<pair<int, int>> primeFactors(int n)
{
    vector<pair<int, int>> ans;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int c = 0;
            while (n % i == 0)
            {
                c++;
                n /= i;
            }
            ans.push_back({i, c});
        }
        if (n == 1)
            break;
    }
    if (n != 1)
    {
        ans.push_back({n, 1});
    }
    return ans;
}
int gcd(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
pair<int, int> GOLDBACH_CONJECTURE(int N)
{
    vector<bool> primes(N + 1, 1);
    primes[0] = 0;
    primes[1] = 0;

    for (int i = 2; i < N + 1; i++)
    {
        if (primes[i] == 1)
        {
            for (int j = 2; j * i <= N; j++)
            {
                primes[i * j] = 0;
            }
        }
    }
    for (int i = 2; i < N + 1; i++)
    {
        if (primes[i] == 1 && primes[N - i])
            return {i, N - i};
    }
    return {0, 0};
}
int main()
{
    using namespace std;
    std::cout << isPrime(83);
    vector<int> v;
    v = primesLessThanN(30);
    printf("\n");
    for (int x : v)
    {
        std::cout << x << " " << isPrime(x) << endl;
    }
    vector<pair<int, int>> ans = primeFactors(730);
    printf("\n");
    printf("\n");
    for (auto x : ans)
    {
        std::cout << x.first << " " << x.second << endl;
    }
    std::cout << endl
              << gcd(100, 20);
    printf("\n");
    auto P = GOLDBACH_CONJECTURE(21);
    std::cout << P.first << " " << P.second;
    return 0;
}