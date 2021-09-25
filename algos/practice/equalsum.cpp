#include <iostream>
#include <vector>
using namespace std;

bool canThreePartsEqualSum(vector<int> &arr)
{
    int sum = 0;
    for (int x : arr)
    {
        sum += x;
    }
    if (sum % 3 != 0)
        return false;
    sum = sum / 3;
    int psum = 0, i, j;
    for (i = 0; i < (int)arr.size(); i++)
    {
        psum += arr[i];
        if (psum == sum)
            break;
    }
    if (i > (int)arr.size() - 2)
        return false;
    psum = 0;
    for (j = i + 1; j < (int)arr.size(); j++)
    {
        psum += arr[j];
        if (psum == sum)
            break;
    }
    if (j >= (int)arr.size() - 1)
        return false;
    psum = 0;
    for (int k = j + 1; k < (int)arr.size(); k++)
    {
        psum += arr[k];
    }
    if (psum == sum)
        return true;
    return false;
}

int main()
{
    vector<int> a = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
    std::cout << canThreePartsEqualSum(a);
    return 0;
}
