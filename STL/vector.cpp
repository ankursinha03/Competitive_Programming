#include <iostream>
#include <vector>
#include <algorithm>

bool comp(float x, float y)
{
    return x > y;
}
int main()
{
    using namespace std;
    vector<float> x = {7.2, 5.2, 4.5, 100.25, 369.2857};

    sort(x.begin(), x.end()); //o(NlogN)
    vector<float>::iterator itr = x.begin();
    while (itr != x.end())
    {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;
    bool is4 = binary_search(x.begin(), x.end(), 4);
    cout << is4 << "\n";

    x.push_back(500);
    x.push_back(500);
    x.push_back(500);
    x.push_back(500);
    x.push_back(500);
    x.push_back(500);
    x.push_back(550);

    vector<float>::iterator it = lower_bound(x.begin(), x.end(), 500);
    cout << *it << endl;
    vector<float>::iterator it2 = upper_bound(x.begin(), x.end(), 500);
    cout << *it2 - *it << endl;
    cout << it2 - it; //gives the no. of occurence of the variable 500
    cout << endl;
    sort(x.begin(), x.end(), comp);
    itr = x.begin();
    while (itr != x.end())
    {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;
    for (float &a : x)
    {
        a++;
        cout << a << " ";
    }

    return 0;
}
