#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MAXBOTONICSUBARRAY(vector<int> v)
{
    if (v.size() == 1)
        return 1;
    int s, b, e;
    s = INT_MAX;
    b = -1;
    e = INT_MIN;
    int diff = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] <= v[i + 1] && i < s && e == INT_MIN)
            s = i;

        if ((v[i] > v[i + 1] && i > s))
            e = i + 1;
        if ((v[i] < v[i + 1] && s < i && e != INT_MIN) || (i + 1 == v.size() - 1))
        {
            if ((i + 1 == v.size() - 1) && e == INT_MIN)
                e = v.size() - 1;
            if (e == v.size() - 1 && s == INT_MAX)
                return v.size();
            b = e - s;
            if (b > diff)
                diff = b;
            s = INT_MAX;
            b = -1;
            e = INT_MIN;
        }
    }

    return diff + 1;
}
int MaxBUTONIC(vector<int> arr)
{
    int n = arr.size();
    int inc[n];

    int dec[n];
    int i, max;

    inc[0] = 1;

    dec[n - 1] = 1;

    for (i = 1; i < n; i++)
        inc[i] = (arr[i] >= arr[i - 1]) ? inc[i - 1] + 1 : 1;

    for (i = n - 2; i >= 0; i--)
        dec[i] = (arr[i] >= arr[i + 1]) ? dec[i + 1] + 1 : 1;

    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
        if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;

    return max;
}
void SubarrayWithSum(vector<int> v, int sum)
{
    int w = 0;
    int s = 0;
    int i, j;
    i = 0;
    j = 0;
    while (s != sum)
    {

        if (s < sum)
        {
            s += v[i];
            i++;
        }
        else if (s > sum)
        {
            s -= v[j];
            j++;
        }
        if (i >= v.size())
        {
            std::cout << 0;
            return;
        }
    }
    i--;
    std::cout << j << " " << i;
}
int main()
{
    using namespace std;
    vector<int> v = {1, 4};
    // std::cout << MAXBOTONICSUBARRAY(v);
    // printf("\n");
    // std::cout << MaxBUTONIC(v);
    SubarrayWithSum(v, 0);
    return 0;
}
