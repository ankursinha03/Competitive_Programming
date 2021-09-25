#include <bits/stdc++.h>
using namespace std;

int minCost(string s, vector<int> &cost)
{
    int ans = 0;

    stack<pair<char, int>> st;

    for (int i = 0; i < cost.size(); i++)
    {
        char ch = s[i];
        if (st.empty())
        {
            st.push({ch, i});
        }
        else if (st.top().first != ch)
        {
            st.push({ch, i});
        }
        else
        {
            auto p = st.top();
            st.pop();
            ans += min(cost[p.second], cost[i]);
            st.push({ch, max(cost[p.second], cost[i])});
        }
    }

    return ans;
}

int numSubmat(vector<vector<int>> &mat)
{
    int R = mat.size();
    int C = mat[0].size();

    vector<vector<int>> aux(R, vector<int>(C));

    for (int i = 0; i < R; i++)
    { //making of auxilary mat

        aux[i][C - 1] = mat[i][C - 1];

        for (int j = C - 2; j >= 0; j--)
        {
            if (mat[i][j])
            {
                aux[i][j] = aux[i][j + 1] + 1;
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << aux[i][j] << " ";
        cout << "\n";
    }

    int ans = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == 0)
                continue;
            int w = aux[i][j];
            ans += w;
            w = min(w, aux[i][j]);
            for (int r = i + 1; r < R; r++)
            {

                w = min(w, aux[r][j]);
                if (aux[r][j] == 0)
                {

                    break;
                }

                w = min(w, aux[r][j]);
                ans += w;
            }
        }
    }

    return ans;
}
int main()
{
    using namespace std;
    vector<vector<int>> mat = {{1, 0, 1},
                               {1, 1, 0},
                               {1, 1, 0}};

    numSubmat(mat);
    vector<int> v = {4, 9, 3, 8, 8, 9};
    minCost("bbbaaa", v);
    return 0;
}