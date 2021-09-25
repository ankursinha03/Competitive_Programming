#include <bits/stdc++.h>
using namespace std;

int BS(vector<int> v, int t)
{
    int L = 0;
    int R = v.size() - 1;
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if (v[mid] == t)
        {
            return mid;
        }
        else if (v[mid] > t)
        {
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }
    return -1;
}

int LB(vector<int> v, int t)
{
    int s = 0;
    int e = v.size() - 1;
    while (e - s > 1)
    {
        int mid = s + (e - s) / 2;
        if (v[mid] <= t)
        {
            s = mid;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

int myLB(vector<int> v, int t)
{
    int ans = -1;
    int s = 0;
    int e = v.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (v[mid] == t)
        {
            return t;
        }
        if (v[mid] < t)
        {
            ans = max(ans, mid);
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int FD(vector<int> v, int s, int e, int t)
{

    int ans = 0;
    if (s < 0)
        return 0;
    if (e == v.size())
        return 0;
    if (s > e)
        return 0;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (v[m] == t)
        {
            ans++;
            ans += FD(v, s, m - 1, t) + FD(v, m + 1, e, t);
            break;
        }
        else if (v[m] < t)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}

int minElementInRotatedArray(vector<int> v)
{

    int L = 0;
    int R = v.size() - 1;
    int ans = INT_MAX;
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if (v[mid] > v[L] && v[L] > v[R])
        {
            ans = min(v[mid], ans);
            L = mid + 1;
        }
        else if (v[mid] > v[L] && v[L] < v[R])
        {
            ans = min(v[mid], ans);
            R = mid - 1;
        }
        else
        {
            ans = min(v[mid], ans);
            R = mid - 1;
        }
    }
    return ans;
}
int maxElementInRotatedArray(vector<int> v)
{
    int ans = INT_MIN;
    int L = 0;
    int R = v.size() - 1;

    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if (v[mid] >= v[L])
        {
            ans = max(ans, v[mid]);
            L = mid + 1;
        }
        else
        {
            ans = max(ans, v[mid]);
            R = mid - 1;
        }
    }
    return ans;
}

int findInRotatedArray(vector<int> v, int t)
{
    int L = 0;
    int R = v.size() - 1;

    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if (v[mid] == t)
        {
            return mid;
        }
        if (v[mid] >= v[L] && v[R] > v[L])
        {
            if (v[mid] > t)
            {
                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }
        else if (v[mid] > v[L] && v[R] < v[L])
        {
            if (v[mid] > t && v[L] > t)
            {
                L = mid + 1;
            }
            else if (v[mid] > t && v[L] <= t)
            {
                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }
        else
        {
            if (v[mid] > t)
            {
                R = mid - 1;
            }
            else if (v[L] > t)
            {
                L = mid + 1;
            }
            else
            {
                R = mid - 1;
            }
        }
    }
    return -1;
}

int searchMatrix(vector<vector<int>> &A, int B)
{
    int m = A.size();
    int n = A[0].size();
    if (A[0][0] == B || A[m - 1][n - 1] == B)
        return 1;
    if (A[m - 1][n - 1] < B)
        return 0;
    if (m == 1 && n == 1)
    {
        if (A[0][0] == B)
            return 1;
        else
            return 0;
    }
    int s = 0;
    int e = m;
    int r;
    while (s <= e)
    {
        if (s == e)
        {
            r = e;
            break;
        }
        int mid = s + (e - s) / 2;
        if (A[mid][0] == B)
            return 1;
        if (A[mid][0] > B)
        {
            e = mid - 1;
        }
        else
        {
            if (B > A[mid][n - 1])
            {
                s = mid + 1;
            }
            else
            {
                r = mid;
                break;
            }
        }
    }

    s = 0;
    e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (A[r][mid] == B)
            return 1;
        if (A[r][mid] > B)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return 0;
}

int maxDistance(vector<int> &nums1, vector<int> &nums2)
{
    int ans = 0;

    for (int i = 0; i < nums1.size(); i++)
    {
        if (i == nums2.size())
            break;
        if (nums2[i] < nums1[i])
            continue;
        int t = nums1[i];
        int s = i;
        int e = nums2.size() - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums2[mid] == t)
            {
                ans = max(ans, mid - i);
            }
            else if (nums2[mid] > t)
            {
                ans = max(ans, mid - i);
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return ans;
}

int canBe(vector<vector<int>> &a, int ans)
{

    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        auto it = upper_bound(a[i].begin(), a[i].end(), ans);

        count = count + it - a[i].begin();
        if (*--it == ans)
            count--;
    }

    return count;
}
int findMatrixMedian(vector<vector<int>> &A)
{
    int s = 0;
    int e = 10;
    int n = A.size();
    int m = A[0].size();
    int target = n * m / 2;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (canBe(A, mid) == target)
            return mid;
        else if (canBe(A, mid) > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return 0;
}

int numOfPairsLessThan(vector<int> &nums, int n)
{
    int s = 0;
    int e = 1;
    int count = 0;
    int ns = nums.size() - 1;
    while (s < ns)
    {
        int d = nums[e] - nums[s];
        if (d <= n)
        {
            e++;
            if (e >= ns && nums[e] - nums[s] <= n)
            {
                e = ns;
                count += e - s;
                s++;
            }
        }
        else
        {
            count += e - s - 1;
            s++;
        }
    }
    return count;
}

int smallestDistancePair(vector<int> &nums, int k)
{
    int ans = 0;
    sort(nums.begin(), nums.end());
    int s = 0;
    int e = nums[nums.size() - 1] - nums[0];

    if (s == e)
        return s;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int count = 0;
        count = numOfPairsLessThan(nums, mid);
        if (count >= k)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> s1 = nums1;
    sort(s1.begin(), s1.end());

    long ans = 0, bnft = 0;
    for (int i = 0; i < nums1.size(); ++i)
    {
        long term = abs(nums1[i] - nums2[i]);
        ans += term;
        auto it = lower_bound(s1.begin(), s1.end(), nums2[i]);
        if (it < s1.end())
            bnft = max(bnft, term - (*it - nums2[i]));
        if (s1.begin() < it)
            bnft = max(bnft, term - (nums2[i] - *prev(it)));

        int L = (it == s1.begin()) ? 0 : *prev(it);
        it = (it == s1.end()) ? prev(it) : it;
        bnft = max(bnft, term - abs(*it - nums2[i]));
        bnft = max(bnft, term - (nums2[i] - L));
    }
    return (ans - bnft) % 1'000'000'007;
}

int main()
{
    using namespace std;
    vector<int> v;
    vector<int> v2;
    // v = {53, 48, 14, 71, 31, 55, 6, 80, 28, 19, 15, 40, 7, 21, 69, 15, 5, 42, 86, 15, 11, 54, 44, 62, 9, 100, 2, 26, 81, 87, 87, 18, 45, 29, 46, 100, 20, 87, 49, 86, 14, 74, 74, 52, 52, 60, 8, 25, 21, 96, 7, 90, 91, 42, 32, 34, 55, 20, 66, 36, 64, 67, 44, 51, 4, 46, 25, 57, 84, 23, 10, 84, 99, 33, 51, 28, 59, 88, 50, 41, 59, 69, 59, 65, 78, 50, 78, 50, 39, 91, 44, 78, 90, 83, 55, 5, 74, 96, 77, 46};
    // v2 = {39, 49, 64, 34, 80, 26, 44, 3, 92, 46, 27, 88, 73, 55, 66, 10, 4, 72, 19, 37, 40, 49, 40, 58, 82, 32, 36, 91, 62, 21, 68, 65, 66, 55, 44, 24, 78, 56, 12, 79, 38, 53, 36, 90, 40, 73, 92, 14, 73, 89, 28, 53, 52, 46, 84, 47, 51, 31, 53, 22, 24, 14, 83, 75, 97, 87, 66, 42, 45, 98, 29, 82, 41, 36, 57, 95, 100, 2, 71, 34, 43, 50, 66, 52, 6, 43, 94, 71, 93, 61, 28, 84, 7, 79, 23, 48, 39, 27, 48, 79};
    // v = {5, 2, 7};
    // v2 = {10, 7, 12};
    // v = {1, 7, 5};
    // v2 = {2, 3, 5};
    v = {150, 100};
    v2 = {90, 10};
    minAbsoluteSumDiff(v, v2);
    // v = {1, 6, 1};
    // smallestDistancePair(v, 3);
    // vector<vector<int>> A;

    // A = {
    //     {1, 3, 5},
    //     {2, 6, 9},
    //     {3, 6, 9},
    // };
    // A = {{1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}};
    // A = {{1, 1}};
    // searchMatrix(A, 0);
    // findMatrixMedian(A);
    // v = {9819, 9508, 7398, 7347, 6337, 5756, 5493, 5446, 5123, 3215, 1597, 774, 368, 313};
    // vector<int> b = {9933, 9813, 9770, 9697, 9514, 9490, 9441, 9439, 8939, 8754, 8665, 8560};
    // maxDistance(v, b);

    // v = {10, 20};
    // std::cout << BS(v, 10);
    // printf("\n");
    // std::cout << LB(v, 5) << " " << myLB(v, 3);

    // v = {1, 2, 2, 2, 2, 3, 4, 5, 6};
    // std::cout << FD(v, 0, v.size() - 1, 2);
    // int x = *max_element(v.begin(), v.end());
    // printf("\n");
    // std::cout << LB(v, 2) << " " << myLB(v, 2);

    v = {1, 3, 4, 4, 4, 4, 4, 4, 5, 7, 9};
    std::cout << *prev(lower_bound(v.begin(), v.end(), 4)) << " " << *upper_bound(v.begin(), v.end(), 4);
    return 0;
}