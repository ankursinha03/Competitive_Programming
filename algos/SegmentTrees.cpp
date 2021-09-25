#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> t;

    int n;

protected:
    int makeTree(int ss, int se, int si, const vector<int> &v)
    {
        if (ss == se)
        {
            t[si] = v[se];
            return t[si];
        }
        int mid = (ss + se) / 2;
        t[si] = makeTree(ss, mid, (2 * si) + 1, v) + makeTree(mid + 1, se, (2 * si) + 2, v);
        return t[si];
    }
    int getSum(int us, int ue, int ss, int se, int si)
    {
        if (ue < ss || us > se)
            return 0;
        if (us <= ss and ue >= se)
            return t[si];
        int mid = (ss + se) / 2;
        return getSum(us, ue, ss, mid, 2 * si + 1) + getSum(us, ue, mid + 1, se, 2 * si + 2); // fn(a,b)
    }
    void updateTree(int ss, int se, int si, const int &index, const int &diff)
    {
        if (index < ss || index > se)
            return;
        t[si] += diff;
        if (se > ss)
        {
            int mid = (ss + se) / 2;
            updateTree(ss, mid, 2 * si + 1, index, diff);
            updateTree(mid + 1, se, 2 * si + 2, index, diff);
        }
    }

public:
    SegmentTree(vector<int> &v)
    {
        n = v.size();
        int ts = 2 * (pow(2, ceil(log2(n)))) - 1;
        t.resize(ts, 0);
        makeTree(0, n - 1, 0, v);
    }
    int sumRange(int us, int ue)
    {
        return getSum(us, ue, 0, n - 1, 0);
    }
    void update(int i, int val, int prev_val)
    {
        int diff = val - prev_val;
        updateTree(0, n - 1, 0, i, diff);
    }
};

int main()
{
    using namespace std;
    vector<int> v = {10, 20, 30, 40};
    SegmentTree st(v);
    std::cout << st.sumRange(1, 3);
    st.update(0, 90, 10);
    printf("\n");
    std::cout << st.sumRange(1, 3);
    printf("\n");
    std::cout << st.sumRange(0, 3);
    return 0;
}