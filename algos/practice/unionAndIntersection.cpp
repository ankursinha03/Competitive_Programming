//to find union and intersection of two sorted arrays

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Union(vector<int> a, vector<int> b)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else
        {
            ans.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
    {
        ans.push_back(a[i]);
        i++;
    }
    while (j < b.size())
    {
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}

vector<int> Intersection(vector<int> a, vector<int> b)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < a.size() && j < b.size())
    {
        if (binary_search(b.begin(), b.end(), a[i]))
        {
            ans.push_back(a[i]);
        }
        i++;
        j++;
    }

    return ans;
}
void display(std::vector<int> &h)
{
    printf("\n");
    for (int i = 0; i < h.size(); i++)
    {
        std::cout << h[i] << " ";
    }
}
int main()
{
    using namespace std;
    vector<int> a = {1, 3, 4, 5, 7}, b = {2, 3, 5, 6};
    vector<int> c;
    c = Union(a, b);
    display(c);
    c = Intersection(a, b);
    ;
    display(c);
    return 0;
}
