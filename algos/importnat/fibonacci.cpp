#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

int recursiveFS(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return recursiveFS(n - 1) + recursiveFS(n - 2);
    unordered_map<int, int> p;
}

int dynamicProgram(int n)
{
    vector<int> a(n + 2);
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}

int DP_constSpace(int n)
{
    int a = 0;
    int b = 1;
    int c;
    int i = 2;
    while (i <= n)
    {
        c = a + b;
        a = b;
        b = c;
        i++;
    }
    return b;
}

void matrixExponentiation(vector<vector<int>> &F, int n)
{
    if (n == 0 || n == 1)
        return;
    unsigned int x, y, z, w;
    if (n % 2 == 0)
    {
        matrixExponentiation(F, n / 2);
        x = F[0][0] * F[0][0] + F[0][1] * F[1][0];
        y = F[0][0] * F[0][1] + F[0][1] * F[1][1];
        z = F[1][0] * F[0][0] + F[1][1] * F[1][0];
        w = F[1][0] * F[0][1] + F[1][1] * F[1][1];

        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }

    if (n % 2 != 0)
    {
        matrixExponentiation(F, (n - 1));
        x = F[0][0] + F[0][1];
        y = F[0][0];
        z = F[1][0] + F[1][1];
        w = F[1][0];

        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }
}
int matrixFibo(int n)
{
    /*
    (1 1)^n     =      (Fn+1 Fn)    
    (1 0)              (Fn   Fn-1)
    */

    vector<vector<int>> v(2);
    v[0].push_back(1);
    v[0].push_back(1);
    v[1].push_back(1);
    v[1].push_back(0);

    matrixExponentiation(v, n - 1);
    return v[0][0];
}

// int divideConquerFS(int n){
//     /*
//     F(n)=(2F(k-1)+F(k))F(k)          k=n/2 (n is even)c`c
//     F(n)= F(k)F(k)+F(k-1)F(k-1)      k=(n+1)/2      (n is odd)
//     */

//    if(n%2==0){
//        return (2*divideConquerFS(n-1)+divideConquerFS(n))
//    }
// }

int fib(int n)
{
    double phi = (1 + sqrt(5)) / 2;
    int ans = round(pow(phi, 50) / sqrt(5));
    return ans;
}
const int MODVAL = 1000000007;
vector<long> vec_one{1, 1, 1, 0};

vector<long> operator*(vector<long> a, vector<long> b)
{
    return {
        (long(a[0] * b[0]) % MODVAL + long(a[1] * b[2]) % MODVAL) % MODVAL,
        (long(a[0] * b[1]) % MODVAL + long(a[1] * b[3]) % MODVAL) % MODVAL,
        (long(a[2] * b[0]) % MODVAL + long(a[3] * b[2]) % MODVAL) % MODVAL,
        (long(a[2] * b[1]) % MODVAL + long(a[3] * b[3]) % MODVAL) % MODVAL};
}

vector<long> power(int n)
{
    if (n == 1)
        return vec_one;
    vector<long> nby2 = power(n / 2);
    return n % 2 ? (nby2 * nby2 * vec_one) : (nby2 * nby2);
}

int solve(int A) { return power(A - 1)[0]; }
int main()
{
    using namespace std;
    std::cout << solve(50);
    return 0;
}