#include <bits/stdc++.h>
using namespace std;

int main()
{
    using namespace std;
    int t;
    cin >> t;
    int n, l, r;
    int ans = 0;
    printf("\n");
    while (t--)
    {
        cin >> n >> l >> r;
        ans = 0;
        vector<int> v(n);
        for (int i = 0; i < v.size(); i++)
        {
            cin >> v[i];
        }
        // v = {2, 5, 5, 1, 1};
        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            int a = lower_bound(v.begin() + i + 1, v.end(), l - v[i]) - v.begin();
            int b = upper_bound(v.begin() + i + 1, v.end(), r - v[i]) - v.begin();

            ans += b - a;
        }
        std::cout << ans << "\n";
    }

    return 0;
}