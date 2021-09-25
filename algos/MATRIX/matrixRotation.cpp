#include <iostream>
#include <vector>
using namespace std;

void Rotate(vector<vector<int>> A)
{
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> B(n, vector<int>(m));

    int p = m - 1;
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            B[i][j] = A[p][q];
            p--;
        }
        p = m - 1;
        q++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << B[i][j] << " ";
        printf("\n");
    }
    A.swap(B);
}

void rotate(vector<vector<int>> &matrix) //clockwise 90
{

    int len = matrix.size();
    for (int i = 0; i < len / 2; i++)
    {
        for (int j = i; j < len - i - 1; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[len - j - 1][i];
            matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
            matrix[len - i - 1][len - j - 1] = matrix[j][len - i - 1];
            matrix[j][len - i - 1] = tmp;
        }
    }
}
void RotateAntiCLW(vector<vector<int>> &matrix)
{
    int len = matrix.size();
    for (int i = 0; i < len / 2; i++)
    {
        for (int j = i; j < len - i - 1; j++)
        {
            int tmp = matrix[i][j]; //1
            matrix[i][j] = matrix[j][len - i - 1];
            matrix[j][len - i - 1] = matrix[len - i - 1][len - j - 1];
            matrix[len - i - 1][len - j - 1] = matrix[len - j - 1][i];
            matrix[len - j - 1][i] = tmp;
        }
    }
}
void Swap(int &A, int &B)
{
    int t;
    t = A;
    A = B;
    B = t;
}
void R(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int level = 0;
    std::cout << "--";
    int maxLevel = n / 2;
    int last = n - 1;
    while (level < maxLevel)
    {
        for (int i = level; i < last; i++)
        {
            swap(matrix[level][i], matrix[i][last]);
            swap(matrix[level][i], matrix[last][last - i + level]);
            swap(matrix[level][i], matrix[last - i + level][level]);
        }
        ++level;
        --last;
    }
}
void RAC(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int level = 0;
    std::cout << "--";
    int maxLevel = n / 2;
    int last = n - 1;
    while (level < maxLevel)
    {
        for (int i = level; i < last; i++)
        {
            swap(matrix[level][i], matrix[i][last]);
            swap(matrix[level][i], matrix[last][last - i + level]);
            swap(matrix[level][i], matrix[last - i + level][level]);
        }
        ++level;
        --last;
    }
}
int main()
{
    using namespace std;
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // Rotate(A);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            std::cout << A[i][j];
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    rotate(A);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            std::cout << A[i][j];
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    RotateAntiCLW(A);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            std::cout << A[i][j];
        }
        printf("\n");
    }
    R(A);
    printf("\n");
    printf("\n");

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            std::cout << A[i][j];
        }
        printf("\n");
    }
    return 0;
}
