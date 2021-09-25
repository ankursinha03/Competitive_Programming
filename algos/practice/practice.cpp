#include <iostream>
#include <cmath>
long reverse(long x)
{
     if(x == 0)
        return 0;
           int res = 0;
    
    while(x)
    {
        if(res > INT_MAX/10 || res < INT_MIN/10)
            return 0;
        
        res = (res * 10) + (x % 10);
        x /= 10;
        
    }
    
    return res;
}
int main()
{
    using namespace std;
    cout << reverse(1534236469);

    return 0;
}
