#include <bits/stdc++.h>
using namespace std;

class Joint
{
    vector<int> v;
    int size;

public:
    Joint(int n)
    {
        vector<int> temp(n, -1);
        v = temp;
    }
    void Insert(vector<pair<int, int>> edgeList)
    {
        for (auto p : edgeList)
        {
            Union(p.first, p.second);
        }
    }
    int Find(int k)
    {
        if (v[k] == -1)
        {
            return k;
        }
        int AbsoluteParent = Find(v[k]);
        if (v[k] != AbsoluteParent)
        {
            v[k] = AbsoluteParent;
        }
        return AbsoluteParent;

        // return v[k]=Find(v[k]);
    }
    int Union(int a, int b)
    {
        int pa = Find(a);
        int pb = Find(b);
        if (pa == pb) //there exists an alternate path as both the parent is same remeber this is an undirected graph
        {
            std::cout << "\nCYCLE EXISTS!!\n";
            return 0;
        }
        v[pa] = pb;
        return 1;
    }
    int check(int a, int b)
    {
        int pa = Find(a);
        int pb = Find(b);
        if (pa == pb)
        {
            return 1;
        }
        return 0;
    }
};
int main()
{
    using namespace std;
    vector<pair<int, int>> edgeList = {{0, 1}, {1, 2}, {2, 3}, {0, 2}};
    Joint jt(4);
    jt.Insert(edgeList);
    std::cout << jt.check(0, 3);
    return 0;
}