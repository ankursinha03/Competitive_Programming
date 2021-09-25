#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;

    int arr[] = {1, 2, 5, 2, 64, 64, 6, 6, 6, 5, 1, 64, 96, 94, 8, 94, 6, 646, 16, 16, 1, 61, 9, 6, 9, 6, 6, 96, 4, 85};

    sort(arr, arr + 31); //this will sort the arr

    for (int i = 0; i < 30; i++)
    {
        cout << arr[i] << " ";
    }
    if (binary_search(arr, arr + 31, 4)) //binary searches the sorted array
    {
        cout << "\n 4 exits! ";
    }

    return 0;
}
