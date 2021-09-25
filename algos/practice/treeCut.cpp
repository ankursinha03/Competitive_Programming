#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{
    // int n = A.size() - 1;
    // if (n == 1)
    // {
    //     return (A[0] - B);
    // }
    // sort(A.begin(), A.end());
    // int cutSoFar = 0;
    // int ans = A[n];
    // for (int i = A.size() - 1; i >= 0; i--)
    // {
    //     int nextH = A[i - 1];
    //     if ((A[i] - nextH) * (n - i + 1) < B - cutSoFar)
    //     {
    //         cutSoFar += (A[i] - nextH) * (n - i + 1);

    //         ans = A[i - 1];
    //     }
    //     else
    //     {
    //         int left = B - cutSoFar;
    //         int j = ceil((float)left / (n - i + 1));
    //         ans = A[i] - j;
    //         return ans;
    //     }
    // }
    // return 0;

    sort(A.begin(), A.end());
    int count = 0, max;
    // int max=A[A.size()-1];
    // cout<<max;
    max = A[A.size() - 1];
    while (count < B)
    {
        count = 0;
        //cout<<max;
        for (int i = 0; i < A.size(); i++)
        {
            //count+=(A[i]-max)>0?max-A[i]:0;
            if ((A[i] - max) > 0)
                count += (A[i] - max);
            else
                count += 0;
        }
        max--;
    }
    return max + 1;
}
int main()
{
    using namespace std;
    vector<int> v = {20, 15, 10, 17};
    solve(v, 7);
    return 0;
}