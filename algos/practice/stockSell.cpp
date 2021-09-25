#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> v)
{
    int ans = 0;
    int profit = 0;
    int b = 0;
    int s = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i + 1] > v[i])
        {
            s++;
            if (s == v.size() - 1)
            {
                profit += v[s] - v[b];
                s++;
                b = s;
            }
        }
        else
        {
            profit += v[s] - v[b];
            s++;
            b = s;
        }
    }
    return profit;
}
void greaterThanRight(vector<int> v)
{
    int maxTillNow = INT_MIN;
    printf("\n");
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] > maxTillNow)
        {
            maxTillNow = v[i];
            cout << maxTillNow << " ";
        }
    }
}
int main()
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    greaterThanRight(arr);
}