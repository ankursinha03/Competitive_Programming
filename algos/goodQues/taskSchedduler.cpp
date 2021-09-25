#include <bits/stdc++.h>
using namespace std;
pair<int,int> robe(TreeNode* node){
        if(node == nullptr) return {0,0};
        int rl,drl,rr,drr;
        auto x = rob(node->left);
        auto y = rob(node->right);
        rl=x.first;
        drl=x.second;
        rr=y.first;
        drr=y.second;
        //case 1 i rob the curr node
        int a = drl+drr+node->val;
        
        int b = rl+rr;
        
        return {a,b};
    }
int leastInterval(vector<char> &tasks, int n)
{
    map<char, int> mp;
    for (auto t : tasks)
        mp[t]++;
    auto cmp = [](pair<char, int> p1, pair<char, int> p2)
    {
        return p1.second < p2.second;
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> maxHeap(cmp);

    for (auto p : mp)
    {
        maxHeap.push(p);
    }
    int ans = 0;
    stack<pair<char, int>> st;

    while (!maxHeap.empty())
    {

        for (int i = 0; i <= n; i++)
        {
            if (!maxHeap.empty())
            {
                auto tp = maxHeap.top();
                maxHeap.pop();
                tp.second--;
                if (tp.second != 0)
                    st.push(tp);
            }

            ans++;
        }
        while (!st.empty())
        {
            maxHeap.push(st.top());
            st.pop();
        }
    }
    return ans;
}
int main()
{
    using namespace std;
    vector<char> v = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    leastInterval(v, 2);
    return 0;
}