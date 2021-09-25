#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
// bool hotel(vector<int> &arrive, vector<int> &depart, int K)
// {
//     // multimap<int, int> mp;
//     // for (int i = 0; i < arrive.size(); i++)
//     // {
//     //     mp.insert({arrive[i], depart[i]});
//     // }
//     // auto firstday=mp.begin();
//     // while (true)
//     // {
//     //     // auto it = mp.equal_range()
//     // }

//     map<int, int> m;
//     for (int i = 0; i < arrive.size(); i++)
//     {
//         m.insert({arrive[i], depart[i]});
//     }
//     auto i = m.begin();
//     auto i2 = i;
//     i2++;
//     while (i2 != m.end())
//     {

//         if (i->second > i2->first)
//         {
//             K--;
//             if (K == 0)
//             {
//                 return 0;
//             }
//         }
//         i++;
//         i2++;
//     }
//     return 1;
// }
bool hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int cnt = 1;
    int i = 0, j = 1;
    while (j < arrive.size())
    {
        if (depart[i] > arrive[j])
            cnt++;
        else
            i++;
        j++;
    }
    return cnt <= K;
}
int maximumGap(const vector<int> &A)
{
    // int i, j;
    // i = 0;
    // j = A.size() - 1;
    // int ans = INT_MIN;
    // for (int i = 0; i < A.size() - 1; i++)
    // {
    //     for (int j = i + 1; j < A.size(); j++)
    //     {
    //         if (A[i] <= A[j])
    //         {
    //             if (j - i > ans)
    //                 ans = j - i;
    //         }
    //     }
    // }
    // return ans;
    vector<pair<int, int>> v;
    for (int i = 0; i < A.size(); i++)
    {
        v.push_back({A[i], i});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int min = v[0].second;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].second < min)
            min = v[i].second;
        else
        {
            if (v[i].second - min > ans)
                ans = v[i].second - min;
        }
    }
    return ans;
}
int main()
{
    using namespace std;
    vector<int> v = {3, 5, 4, 2};
    std::cout << maximumGap(v);
    return 0;
}