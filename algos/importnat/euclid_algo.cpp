//used to calculate greatest common divisior
#include <iostream>

long GCD(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return GCD(b, a % b);
    }
}
long GCD2(long a, long b) //doesn't use recursion
{
    while (b != 0)
    {
        long rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int main()
{
    using namespace std;
    cout << "Enter two number whose GCD is required: ";
    long x, y;
    cin >> x >> y;
    cout << "\n The GCD of the input is: " << GCD(x, y);
    cout << "\n The GCD of the inputed numbers is: " << GCD2(x, y);
    return 0;
}
