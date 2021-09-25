#include <iostream>
#include <cmath>

long long exponential(long long x, long long n)
{
    if (x == 1)
    {
        return 1;
    }

    if (n == 0)
    {
        return 1;
    }

    if (n == 1)
    {
        return x;
    }

    if (n % 2 == 0)
    {
        return exponential(x * x, n / 2);
    }

    else
    {
        return exponential(x * x, (n - 1) / 2) * x;
    }
}
//the abovew algo is not great as it calls for same power twice

float exp(float a, int b)
{
    if (b == 0)
        return 1.0;
    if (b == 1)
        return (float)a;
    float t = exp(a, b / 2);
    if (b % 2 == 0)
        return (float)t * t;
    else
    {
        if (b > 0)
            return (float)t * t * a;
        else
            return (float)t * t / a;
    }
}

int power(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result *= a;

        a *= a;
        b /= 2;
    }
    return result;
}
int main()
{
    using namespace std;
    int a, b;
    cout << "Enter the base and power: ";
    cin >> a >> b;

    // cout << "\nThe based raised to the power is: " << exponential(a, b);
    cout << "\nThe based raised to the power is: " << pow(a, b);
    std::cout << "\n nega " << exp(a, b) << " iterative: " << power(a, b);
    return 0;
}
