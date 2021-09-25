#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>
#include <bitset>
#include <map>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int> &deck)
{

    sort(deck.begin(), deck.end());
    vector<int> ans(deck.size());
    deque<int> dq;
    for (int i = deck.size() - 1; i > 0; i--)
    {
        dq.push_front(deck[i]);
        if (dq.size() == 1)
            continue;
        dq.push_front(dq.back());
        dq.pop_back();
    }
    dq.push_front(deck[0]);
    for (int i = 0; i < deck.size(); i++)
    {
        ans[i] = dq.front();
        dq.pop_front();
    }

    return ans;
}
int numTeams(vector<int> &rating)
{
    // int n = rating.size();

    // vector<int> mx1(n);
    // vector<int> mx2(n);
    // vector<int> mn1(n);
    // vector<int> mn2(n);
    // mx1[n - 1] = rating[n - 1];
    // mn2[n - 1] = rating[n - 1];
    // for (int i = n - 2; i >= 0; i--)
    // {
    //     mx1[i] = (mx1[i + 1] > rating[i]) ? mx1[i + 1] : rating[i];
    //     mn2[i] = (mn2[i + 1] < rating[i]) ? mn2[i + 1] : rating[i];
    // }
    // mn1[0] = rating[0];
    // mx2[0] = rating[0];
    // for (int i = 1; i < n; i++)
    // {
    //     mn1[i] = (mn1[i - 1] < rating[i]) ? mn1[i - 1] : rating[i];
    //     mx2[i] = (mx2[i - 1] > rating[i]) ? mx2[i - 1] : rating[i];
    // }
    // int ans = 0;

    // for (int i = 1; i < n - 1; i++)
    // {
    //     if (mx1[i] > rating[i] && rating[i] > mn1[i])
    //         ans++;
    //     if (mx2[i] > rating[i] && rating[i] > mn2[i])
    //         ans++;
    // }

    // return ans;

    int ans = 0;
    for (int i = 1; i < rating.size() - 1; i++)
    {
        int leftgreat = 0;
        int rightgreat = 0;
        for (int j = 0; j < i; j++)
        {
            if (rating[i] > rating[j])
                leftgreat++;
        }
        for (int j = i + 1; j < rating.size(); j++)
        {
            if (rating[i] < rating[j])
                rightgreat++;
        }
        ans += leftgreat * rightgreat + (i - leftgreat) * (rating.size() - i - rightgreat - 1);
    }
    return ans;
}
int countSquares(vector<vector<int>> &matrix)
{ //brute force algo which can improved by applying sliding window method however dp provides much better approach
    int m, n;
    m = matrix.size();
    n = matrix[0].size();
    int s = 1;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
                ans++;
        }
    }
    if (ans == 0)
        return 0;
    int k;
    while (s < min(m, n))
    {
        for (int i = 0; i < m - s; i++)
        {
            for (int j = 0; j < n - s; j++)
            {
                k = 0;
                for (int p = i; p <= i + s; p++)
                {
                    for (int q = j; q <= j + s; q++)
                    {
                        k += matrix[p][q];
                        if (matrix[p][q] == 0)
                            break;
                    }
                }
                if (k == (s + 1) * (s + 1))
                    ans++;
            }
        }

        s++;
    }

    return ans;
}
int countSquaresDP_Approach(vector<vector<int>> &matrix)
{
    vector<vector<int>> v;
    v = matrix;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[i][j] == 0)
                continue;
            int f = min(min(v[i][j - 1], v[i - 1][j]), v[i - 1][j - 1]);
            v[i][j] = (f == 0) ? v[i][j] : f + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += v[i][j];
        }
    }

    return ans;
}
int findTheWinner(int n, int k)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }
    k--;
    int s = 0;
    int e = 0;
    while (v.size() > 1)
    {
        e = s + k;
        while (e >= v.size())
        {
            e -= v.size();
        }
        if (v.size() > 1)
            v.erase(v.begin() + e);
        s = e;
    }

    return v[0];
}
int reinitializePermutation(int n)
{
    vector<int> perm(n);
    vector<int> original(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
    }
    int ans = 0;
    original = perm;
    while (arr != original)
    {
        ans++;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                arr[i] = perm[i / 2];
            if (i % 2 == 1)
                arr[i] = perm[n / 2 + (i - 1) / 2];
        }
        perm = arr;
    }

    return ans;
    // int pos=n/2;
    //     int res=1;
    //     while(pos!=1)
    //     {
    //         res++;
    //         if(pos%2==0) pos=pos/2; //if 1 set on even position
    //         else pos=n/2+(pos-1)/2; //if 1 set on odd position
    //     }
    //     return res;
}
vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
{
    int x, y;
    x = king[0];
    y = king[1];
    map<vector<int>, int> mp;
    for (int i = 0; i < queens.size(); i++)
    {
        mp[queens[i]] = 0;
    }

    vector<vector<int>> ans;
    for (int i = y - 1; i >= 0; i--)
    {
        if (mp.find({x, i}) != mp.end())
        {
            ans.push_back({x, i});
            break;
        }
    }
    for (int i = y + 1; i < 8; i++)
    {
        if (mp.find({x, i}) != mp.end())
        {
            ans.push_back({x, i});
            break;
        }
    }
    for (int i = x - 1; i >= 0; i--)
    {
        if (mp.find({i, y}) != mp.end())
        {
            ans.push_back({i, y});
            break;
        }
    }
    for (int i = x + 1; i < 8; i++)
    {
        if (mp.find({i, y}) != mp.end())
        {
            ans.push_back({i, y});
            break;
        }
    }
    while (x < 8 && y < 8)
    {
        x++;
        y++;
        if (mp.find({x, y}) != mp.end())
        {
            ans.push_back({x, y});
            break;
        }
    }
    x = king[0];
    y = king[1];
    while (x >= 0 && y >= 0)
    {
        x--;
        y--;
        if (mp.find({x, y}) != mp.end())
        {
            ans.push_back({x, y});
            break;
        }
    }
    x = king[0];
    y = king[1];
    while (x < 8 && y >= 0)
    {
        y--;
        x++;
        if (mp.find({x, y}) != mp.end())
        {
            ans.push_back({x, y});
            break;
        }
    }
    x = king[0];
    y = king[1];
    while (x >= 0 && y < 8)
    {
        x--;
        y++;
        if (mp.find({x, y}) != mp.end())
        {
            ans.push_back({x, y});
            break;
        }
    }

    return ans;
}
vector<int> findDuplicates(vector<int> &nums)
{

    vector<int> ans;
    if (nums.size() == 0 || nums.size() == 1)
        return ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
            ans.push_back(abs(nums[i]));
        else
        {
            nums[abs(nums[i]) - 1] *= -1;
        }
    }
    return ans;
}
vector<int> pancakeSort(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    vector<int> ref(n);
    for (int i = 0; i < n; i++)
    {
        ref[i] = i + 1;
    }
    int i = 0;
    int j = n - 1;
    while (arr != ref)
    {
        if (arr[j] == ref[j])
        {
            j--;
        }
        else
        {
            for (int k = 0; k <= j; k++)
            {
                if (arr[k] == ref[j])
                {
                    if (k == 0)
                    {
                        reverse(arr.begin(), arr.begin() + j + 1);
                        ans.push_back(j + 1);
                        break;
                    }
                    else
                    {
                        reverse(arr.begin(), arr.begin() + k + 1);
                        ans.push_back(k + 1);
                        break;
                    }
                }
            }
        }
    }
    return ans;
}

int minSetSize(vector<int> &arr)
{
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    int ans = 0;
    vector<int> v(mp.size());
    auto it = mp.begin();
    for (int i = 0; i < mp.size() && it != mp.end(); i++)
    {
        v[i] = it->second;
        it++;
    }
    mp.clear();
    sort(v.begin(), v.end());
    int num = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        num += v[i];
        ans++;
        if (num >= arr.size() / 2)
        {
            return ans;
        }
    }

    return ans;
}
int search(vector<vector<int>> &grid, int i, int j, int m, int n)
{
    if (i < 0 || j < 0 || i == m || j == n)
        return 0;
    if (grid[i][j] != 1)
        return 0;
    int cr = 1;
    grid[i][j]++;
    cr += search(grid, i, j + 1, m, n);
    cr += search(grid, i + 1, j, m, n);
    cr += search(grid, i, j - 1, m, n);
    cr += search(grid, i - 1, j, m, n);
    return cr;
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int area = 0;
    int cr = 0;
    int m = grid.size();
    int n = grid[0].size();
    if (m == 0 || n == 0)
        return 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cr = 0;
            if (grid[i][j] == 1)
            {
                cr++;
                grid[i][j]++;
                cr += search(grid, i, j + 1, m, n);
                cr += search(grid, i + 1, j, m, n);
                cr += search(grid, i, j - 1, m, n);
                cr += search(grid, i - 1, j, m, n);
                if (cr > area)
                    area = cr;
            }
        }
    }

    return area;
}
vector<int> solvex(vector<int> &A)
{
    vector<int> ans;
    vector<int> right(A.size());
    right[A.size() - 1] = A.back();
    for (int i = A.size() - 2; i >= 0; i--)
    {
        if (A[i] > right[i + 1])
            right[i] = A[i];
        else
            right[i] = right[i + 1];
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == right[i])
            ans.push_back(A[i]);
    }
    return ans;
}

int main()
{
    using namespace std;
    // vector<int> v = {17, 13, 11, 2, 3, 5, 7};
    // // deckRevealedIncreasing(v);
    // v = {2, 5, 3, 4, 1};
    // numTeams(v);

    // vector<vector<int>> matrix = {
    //     {1, 0, 1},
    //     {1, 1, 0},
    //     {1, 1, 0}};
    // std::cout << countSquares(matrix);
    // printf("\n");
    // std::cout << countSquaresDP_Approach(matrix);

    // findTheWinner(6, 5);

    // reinitializePermutation(6);

    // vector<vector<int>> queens;
    // vector<int> king;
    // queens = {{5, 6}, {7, 7}, {2, 1}, {0, 7}, {1, 6}, {5, 1}, {3, 7}, {0, 3}, {4, 0}, {1, 2}, {6, 3}, {5, 0}, {0, 4}, {2, 2}, {1, 1}, {6, 4}, {5, 4}, {0, 0}, {2, 6}, {4, 5}, {5, 2}, {1, 4}, {7, 5}, {2, 3}, {0, 5}, {4, 2}, {1, 0}, {2, 7}, {0, 1}, {4, 6}, {6, 1}, {0, 6}, {4, 3}, {1, 7}};
    // king = {3, 4};
    // queensAttacktheKing(queens, king);

    // vector<int> v = {4, 3, 2, 7, 8, 2, 3, 1};
    // findDuplicates(v);

    // vector<int> v = {3, 2, 4, 1};
    // pancakeSort(v);

    // vector<int> v = {7, 7, 7, 7, 7, 7};
    // minSetSize(v);

    // vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    // std::cout << maxAreaOfIsland(grid);
    vector<int> A = {16, 17, 4, 3, 5, 2};
    solvex(A);
    return 0;
}