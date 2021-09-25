#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

int repeatedNumber(const vector<int> &A)
{
    // unordered_map<int, int> m;
    // for (int i = 0; i < A.size(); i++)
    // {
    //     auto it = m.find(A[i]);
    //     if (it == m.end())
    //     {
    //         m[A[i]]++;
    //     }
    //     else
    //     {
    //         return A[i];
    //     }
    // }
    // return -1;

    vector<int> B;
    B.assign(A.begin(), A.end());
    B[0] *= -1;
    for (int i = 0; i < B.size(); i++)
    {
        if (B[abs(B[i])] < 0)
        {
            return abs(B[i]);
        }
        else
        {
            B[abs(B[i])] *= -1;
        }
    }
    return -1;

    int slow = A[0];
    int fast = A[A[0]];
    while (slow != fast)
    {
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;
    while (slow != fast)
    {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}

int maximumGap(const vector<int> &A) //bucket ques
{
    if (A.size() < 2)
        return 0;
    vector<int> B;
    B.assign(A.begin(), A.end());
    sort(B.begin(), B.end());
    int maxDiff = 0;
    for (int i = 0; i < B.size() - 1; i++)
    {
        if (B[i + 1] - B[i] > maxDiff)
            maxDiff = B[i + 1] - B[i];
    }
    B.clear();
    return maxDiff;
}
vector<int> wave(vector<int> &A)
{
    vector<int> ans;
    ans.assign(A.begin(), A.end());
    sort(ans.begin(), ans.end());
    int t;
    for (int i = 0; i < A.size() - 1; i += 2)
    {
        t = ans[i];
        ans[i] = ans[i + 1];
        ans[i + 1] = t;
    }
    return ans;
}

int main()
{
    using namespace std;
    vector<int> v = {47, 4, 0, 12, 47, 31, 15, 49, 29, 33, 7, 22, 26, 24, 16};
    vector<int> v2 = {95, 4, 26, 16, 51, 79, 43, 58, 32, 80, 30, 27, 29, 54, 16};

    std::cout << maximumGap(v);
    return 0;
}