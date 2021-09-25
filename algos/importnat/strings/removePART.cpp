#include <bits/stdc++.h>
using namespace std;
string removeOccurrences(string s, string part)
{
    if (part.length() > s.length())
        return s;
    stack<char> st;
    int n = s.length();
    int m = part.size();
    int j;
    for (int i = 0; i < n; i++)
    {
        if (st.size() < m - 1)
        {
            st.push(s[i]);
        }
        else
        {
            if (s[i] != part.back())
            {
                st.push(s[i]);
            }
            else
            {
                st.push(s[i]);
                bool flag = 0;

                for (j = m - 1; j >= 0; j--)
                {
                    if (st.top() == part[j])
                    {
                        st.pop();
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                if (j == -1)
                    continue;
                else
                {
                    j++;
                    for (; j < m; j++)
                    {
                        st.push(part[j]);
                    }
                }
            }
        }
    }

    string ans;

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    vector<int> table(n * n + 1, -1);
    vector<bool> vis(n * n + 1, 0);
    bool direction = 1;
    int index = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (direction)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != -1)
                {
                    table[index++] = board[i][j];
                    continue;
                }
                table[index] = index;
                index++;
            }
            direction = 0;
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (board[i][j] != -1)
                {
                    table[index++] = board[i][j];
                    continue;
                }
                table[index] = index;
                index++;
            }
            direction = 1;
        }
    }
    queue<pair<int, int>> q;
    q.push({1, 0});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        for (int i = p.first + 1; i <= min(n * n, p.first + 6); i++)
        {
            if (table[i])
                if (vis[i])
                    continue;
            vis[i] = 1;
            q.push({table[i], p.second + 1});
        }
    }

    return -1;
}
bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    set<int> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.insert(nums[i]);
        }
        else
        {

            if (st.size() < k)
            {
                auto LB = st.lower_bound(nums[i]);
                if (LB == st.end())
                {
                    if (abs(nums[i] - *prev(LB)) <= t)
                        return 1;
                }
                else if (LB == st.begin())
                {
                    if (abs(nums[i] - *LB) <= t)
                        return 1;
                }
                else
                {
                    if (abs(nums[i] - *prev(LB)) <= t)
                        return 1;
                    if (abs(nums[i] - *LB) <= t)
                        return 1;
                }
                st.insert(nums[i]);
            }
            else
            {
                st.erase(nums[i - k]);
                auto LB = st.lower_bound(nums[i]);
                if (LB == st.end())
                {
                    if (abs(nums[i] - *prev(LB)) <= t)
                        return 1;
                }
                else if (LB == st.begin())
                {
                    if (abs(nums[i] - *LB) <= t)
                        return 1;
                }
                else
                {
                    if (abs(nums[i] - *prev(LB)) <= t)
                        return 1;
                    if (abs(nums[i] - *LB) <= t)
                        return 1;
                }
                st.insert(nums[i]);
            }
        }
    }
    return 0;
}
int largest1BorderedSquare(vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<vector<int>> ver(n, vector<int>(n));
    vector<vector<int>> hor(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += grid[i][j];
            hor[i][j] = sum;
        }
    }

    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += grid[i][j];
            ver[i][j] = sum;
        }
    }

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int p = 1; (i + p < n && j + p < n); p++)
            {
                if (grid[i][j] != grid[i + p][j + p] || grid[i][j + p] != grid[i][j] || grid[i + p][j] != grid[i][j])
                    continue;
                if (grid[i][j] == 1)
                {
                    bool a = ver[i + p][j] - ver[i][j] == p;
                    bool b = ver[i + p][j + p] - ver[i][j + p] == p;
                    bool c = hor[i][j + p] - hor[i][j] == p;
                    bool d = hor[i + p][j + p] - hor[i + p][j] == p;
                    if (a && b && c && d)
                    {
                        ans = max(ans, (p + 1) * (p + 1));
                    }
                }
                else
                {
                    if (ver[i + p][j] - ver[i][j] == 0 &&
                        ver[i + p][j + p] - ver[i][j + p] == 0 &&
                        hor[i][j + p] - hor[i][j] == 0 &&
                        hor[i + p][j + p] - hor[i][j + p] == 0)
                    {
                        ans = max(ans, (p + 1) * (p + 1));
                    }
                }
            }
        }
    }

    return ans;
}
int main()
{
    using namespace std;
    vector<int> vv = {1, 5, 9, 1, 5, 9};
    // containsNearbyAlmostDuplicate(vv, 2, 3);
    vector<vector<int>> board = {{-1, -1, -1, -1, -1, -1},
                                 {-1, -1, -1, -1, -1, -1},
                                 {-1, -1, -1, -1, -1, -1},
                                 {-1, 35, -1, -1, 13, -1},
                                 {-1, -1, -1, -1, -1, -1},
                                 {-1, 15, -1, -1, -1, -1}};

    // snakesAndLadders(board);
    board = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    largest1BorderedSquare(board);
    // removeOccurrences("daabcbaabcbc", "abc");
    return 0;
}