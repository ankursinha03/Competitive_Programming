#include <iostream>
#include <cmath>
#include <vector>
void print(std::vector<int> &v)
{
    printf("\n");
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
}
int main()
{
    using namespace std;

    cout << "enter n ";
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int mid = floor(v.size() / 2);
    cout << "\n mid : " << mid;
    std::vector<int> L;
    std::vector<int> R;
    L.assign(v.begin(), v.begin() + mid);
    // L.push_back(v[mid]);

    R.assign(v.begin() + mid, v.end());

    print(v);
    printf("\n");
    print(L);
    print(R);

    return 0;
}
