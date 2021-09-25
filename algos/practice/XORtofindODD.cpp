#include <iostream>
#include <vector>

// The Best Solution is to do bitwise XOR of all the elements.
// XOR of all elements gives us odd occurring elements.
// Please note that the XOR of two elements is 0 if both elements are the same and the XOR of a number x with 0 is x

int ODD_occuring_number(std::vector<int> a)
{
    int k = 0;
    for (int i = 0; i < a.size(); i++)
    {
        k = k ^ a[i];
    }
    return k;
}
int main()
{
    using namespace std;
    vector<int> v = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
    cout << ODD_occuring_number(v);

    return 0;
}
