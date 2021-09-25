#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void threeElements(vector<int> v)
{
    int j, k;
    for (int i = 0; i < v.size(); i++)
    {
        j = i + 1;
        if (v[i] > v[j])
        {
            continue;
        }
        else
        {
            k = j + 1;
            while (k < v.size())
            {
                if (v[j] < v[k])
                {
                    cout << v[i] << v[j] << v[k];
                    break;
                }
                else
                {
                    k++;
                }
            }
        }
    }
}
void find3Numbers(vector<int> &nums)
{

    // If number of elemets < 3
    // then no triplets are possible
    if (nums.size() < 3)
    {
        cout << "No such triplet found";
        return;
    }

    // track best sequence length
    // (not current sequence length)
    int seq = 1;

    // min number in array
    int min_num = nums[0];

    // least max number in best sequence
    // i.e. track arr[j] (e.g. in
    // array {1, 5, 3} our best sequence
    // would be {1, 3} with arr[j] = 3)
    int max_seq = INT_MIN;

    // save arr[i]
    int store_min = min_num;

    // Iterate from 1 to nums.size()
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == min_num)
            continue;

        else if (nums[i] < min_num)
        {
            min_num = nums[i];
            continue;
        }

        // this condition is only hit
        // when current sequence size is 2
        else if (nums[i] < max_seq)
        {

            // update best sequence max number
            // to a smaller value
            // (i.e. we've found a
            // smaller value for arr[j])
            max_seq = nums[i];

            // store best sequence start value
            // i.e. arr[i]
            store_min = min_num;
        }

        // Increase best sequence length &
        // save next number in our triplet
        else if (nums[i] > max_seq)
        {
            seq++;

            // We've found our arr[k]!
            // Print the output
            if (seq == 3)
            {
                cout << "Triplet: " << store_min << ", " << max_seq << ", " << nums[i] << endl;
                return;
            }
            max_seq = nums[i];
        }
    }

    // No triplet found
    cout << "No such triplet found";
}
bool check(vector<int> &nums)
{
    vector<int> num;
    num = nums;
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++)
    {
        if (nums[i] == num[i])
    }
}
int main()
{
    using namespace std;
    vector<int> v = {2, 1, 3, 4};
    // threeElements(v);
    // find3Numbers(v);
    std::cout << check(v);
    return 0;
}
