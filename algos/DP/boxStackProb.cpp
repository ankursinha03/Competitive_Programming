#include <bits/stdc++.h>
using namespace std;

struct Box
{
    int h, w, l;
};
int maxHeight(vector<int> height, vector<int> width, vector<int> length)
{
    const int n = height.size();
    vector<Box> buff(3 * n);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        buff[index].h = height[i];
        buff[index].l = max(length[i], width[i]);
        buff[index].w = min(length[i], width[i]);
        index++;

        // First rotation of box
        buff[index].h = width[i];
        buff[index].l = max(height[i], length[i]);
        buff[index].w = min(height[i], length[i]);
        index++;

        // Second rotation of box
        buff[index].h = length[i];
        buff[index].l = max(height[i], width[i]);
        buff[index].w = min(height[i], width[i]);
        index++;
    }

    sort(buff.begin(), buff.end(), [](const Box a, const Box b)
         { return a.l * a.w > b.l * b.w; });

    vector<int> dp(3 * n);
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i] = buff[i].h;
    }

    for (int i = 1; i < 3 * n; i++)
        for (int j = 0; j < i; j++)
            if (buff[i].w < buff[j].w && buff[i].l < buff[j].l && dp[i] < dp[j] + buff[i].h)
            {
                dp[i] = dp[j] + buff[i].h;
            }

    return *max_element(dp.begin(), dp.end());
}

int maxKandane(vector<int> v)
{
    int max = INT_MIN;
    int ans = 0;
    int psum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
        psum += v[i];
        if (psum > ans)
        {
            ans = psum;
        }
        if (psum < 0)
        {
            psum = 0;
        }
    }
    if (max < 0)
        return max;
    return ans;
}

int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    vector<int> t(R);
    int ans = INT_MIN;
    for (int l = 0; l < C; l++)
    {
        fill(t.begin(), t.end(), 0);
        for (int r = l; r < C; r++)
        {
            for (int i = 0; i < R; i++)
            {
                t[i] += M[i][r];
            }
            int temp = maxKandane(t);
            if (temp > ans)
            {
                ans = temp;
            }
        }
    }
    return ans;
}
int main()
{
    using namespace std;
    vector<int> v;
    vector<int> h = {4, 1, 4, 10};
    vector<int> w = {6, 2, 5, 12};
    vector<int> l = {7, 3, 6, 32};
    std::cout << maxHeight(h, w, l);

    vector<vector<int>> M = {{-1, -2}, {-3, -4}};
    maximumSumRectangle(2, 2, M);
    return 0;
}