#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int m = B.size();
    if (m < n)
        return findMedianSortedArrays(B, A);
    if (A.size() == 0)
    {
        if (m % 2 == 1)
            return B[m / 2];
        else
        {
            return (B[m / 2] + B[(m - 1) / 2]) / 2;
        }
    }
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int c1 = (s + e) / 2;
        int c2 = ((n + m + 1) / 2) - c1;

        int l1, r1, l2, r2;

        l1 = ((c1 == 0) ? INT_MIN : A[c1 - 1]);
        l2 = ((c2 == 0) ? INT_MIN : B[c2 - 1]);

        r1 = ((c1 == n) ? INT_MAX : A[c1]);
        r2 = ((c2 == m) ? INT_MAX : B[c2]);

        if (l1 <= r2 && l2 <= r1)
        {
            if ((m + n) % 2 == 1)
            {
                return max(l1, l2);
            }
            else
            {
                return ((min(r1, r2) + max(l1, l2))) / 2.0;
            }
        }
        else if (l1 > r2)
        {
            e = l1 - 1;
        }
        else
        {
            s = l1 + 1;
        }
    }
    return 0;
}
// int n = A.size();
//     int m = B.size();

//     if (m < n)
//     {
//         return findMedianSortedArrays(B, A);
//     }

//     int s = 0;
//     int e = n;
//     const int total = n + m;

//     while (s <= e)
//     {
//         int mid1 = (s + e) / 2;
//         int mid2 = (total + 1) / 2 - mid1;

//         int l1 = (mid1 == 0 ? INT_MIN : A[mid1 - 1]);
//         int l2 = (mid2 == 0 ? INT_MIN : B[mid2 - 1]);

//         int r1 = (mid1 == n ? INT_MAX : A[mid1]);
//         int r2 = (mid2 == m ? INT_MAX : B[mid2]);

//         if (l1 <= r2 && l2 <= r1)
//         {
//             if (total % 2 == 0)
//             {
//                 return (max(l1, l2) + min(r1, r2)) / 2.0;
//             }
//             else
//             {
//                 return max(l1, l2);
//             }
//         }
//         else if (l1 > r2)
//         {
//             e = mid1 - 1;
//         }
//         else
//         {
//             s = mid1 + 1;
//         }
//     }

//     return 0.0;
int main()
{
    using namespace std;
    vector<int> v1 = {-37, 4, 7, 13, 29, 49, 50};
    vector<int> v2 = {-24, -14, 32};
    std::cout << findMedianSortedArrays(v1, v2);
    return 0;
}