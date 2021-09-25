#include <iostream>
#include <vector>
#include <algorithm>

#include <stack>

using namespace std;

vector<int> minOperations(string boxes)
{
    vector<int> ans(boxes.length());
    int sun = 0;

    for (int i = 0; i < boxes.length(); i++)
    {
        for (int s = i + 1; s < boxes.length(); s++)
        {
            if (boxes[s] == '1')
                ans[i] += s - i;
        }
        for (int p = i - 1; p >= 0; p--)
        {
            if (boxes[p] == '1')
                ans[i] += i - p;
        }
    }
    return ans;
}
vector<int> processQueries(vector<int> &queries, int m)
{
    vector<int> p(m);
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        p[i] = i + 1;
    }
    int i = 0;
    while (i < queries.size())
    {
        int j = queries[i];
        int q;
        for (q = 0; q < p.size(); q++)
        {
            if (p[q] == j)
            {
                ans.push_back(q);
                break;
            }
        }

        for (int w = q; w > 0; w--)
        {
            p[w] = p[w - 1];
        }
        p[0] = j;
        i++;
    }
    return ans;
}
int main()
{
    using namespace std;
    vector<int> v = {4, 1, 2, 2};
    string s = "001011";
    processQueries(v, 4);
    minOperations(s);
    return 0;
}