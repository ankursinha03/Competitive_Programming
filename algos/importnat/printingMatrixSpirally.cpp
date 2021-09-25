
#include <iostream>
#include <vector>
using namespace std;

#define R 4
#define C 4

void print(vector<vector<int>> &arr, int i, int j, int m, int n)
{

    if (i >= m or j >= n)
        return;

    for (int p = j; p < n; p++)
        cout << arr[i][p] << " ";

    for (int p = i + 1; p < m; p++)
        cout << arr[p][n - 1] << " ";

    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            cout << arr[m - 1][p] << " ";

    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            cout << arr[p][j] << " ";

    print(arr, i + 1, j + 1, m - 1, n - 1);
}

int main()
{

    vector<vector<int>> MAT = {{1, 2, 3, 4, 20},
                               {5, 6, 7, 8, 21},
                               {9, 10, 11, 12, 22},
                               {13, 14, 15, 16, 23},
                               {31, 32, 33, 34, 35}};

    // Function Call
    print(MAT, 0, 0, MAT.size(), MAT[0].size());
    return 0;
}