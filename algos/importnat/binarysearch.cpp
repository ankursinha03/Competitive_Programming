#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int BinarySearch(std::vector<int> v, int start, int end, int key)
{

    int mid = floor((start + end) / 2);
    if (start == end && v[mid] != key)
    {
        return -1;
    }
    if (v[mid] == key)
    {
        return mid;
    }
    else if (v[mid] < key)
    {
        return (BinarySearch(v, mid + 1, end, key));
    }
    else if (v[mid] > key)
    {
        return (BinarySearch(v, start, mid, key));
    }
    return -1;
}

int main()
{
    using namespace std;
    int n;
    printf("Enter the number of elements: ");
    int i = 0;
    cin >> n;
    vector<int> a(n);
    while (n--)
    {
        cin >> a[i];
        i++;
    }
    cout << "enter key: ";
    int k;
    cin >> k;
    cout << BinarySearch(a, 0, i - 1, k);
    printf("\n");
    cout << binary_search(a.begin(), a.end(), k);
    auto Lbound = lower_bound(a.begin(), a.end(), k);
    auto Ubound = upper_bound(a.begin(), a.end(), k);
    printf("\n");
    cout << Lbound - a.begin() << " " << *Lbound;
    printf("\n");
    cout << Ubound - a.begin() << " " << *Ubound;

    return 0;
}
