#include <iostream>
#include <vector>
#include <cmath>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void print(std::vector<int> &v)
{
    printf("\n");
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
}
void SelectionSort(std::vector<int> &a)
{
    int i = 0;
    int min, l;
    int temp;
    l = 0;
    while (i != a.size())
    {
        min = a[i];
        for (int k = i; k < a.size(); k++)
        {
            if (a[k] < min)
            {
                min = a[k];
                l = k;
            }
        }
        temp = a[i];
        a[i] = min;
        a[l] = temp;
        i++;
    }
}

void bubblesort(std::vector<int> &v)
{
    int n = v.size();
    bool flag;
    int t = 0;
    int temp;
    for (int k = 0; k < n - t; k++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
        t++;
    }
}

void insertionSort(std::vector<int> &v)
{
    // int n = v.size();
    // int temp;
    // int curr, cp, k;
    // for (int i = 1; i < n; i++)
    // {
    //     curr = v[i];
    //     k = i - 1;
    //     while (k >= 0 && v[k] > curr)
    //     {
    //         v[k + 1] = v[k];
    //         k--;
    //     }
    //     v[k + 1] = curr;
    // }
    int curr;
    int pos;
    for (int i = 1; i < v.size(); i++)
    {
        curr = v[i];
        int k = i - 1;
        pos = i;
        while (k >= 0 && v[k] > curr)
        {
            swap(&v[k], &v[pos]);
            k--;
            pos--;
        }
    }
}

void merge(std::vector<int> &L, std::vector<int> &R, std::vector<int> &P)
{
    int j = 0, k = 0;
    int i = 0;
    while (j < L.size() && k < R.size())
    {
        if (L[j] < R[k])
        {
            P[i] = L[j];
            j++;
            i++;
        }
        else
        {
            P[i] = R[k];
            k++;
            i++;
        }
    }
    while (j < L.size())
    {
        P[i] = L[j];
        j++;
        i++;
    }
    while (k < R.size())
    {
        P[i] = R[k];
        k++;
        i++;
    }
}
void MergeSort(std::vector<int> &v)
{
    if (v.size() < 2)
    {
        return;
    }
    int mid = floor(v.size() / 2);
    std::vector<int> L, R;
    L.assign(v.begin(), v.begin() + mid);

    R.assign(v.begin() + mid, v.end());

    MergeSort(L);
    MergeSort(R);
    merge(L, R, v);
}

int Partiond(std::vector<int> &v, int s, int e)
{
    int pivot = v[e];
    int index = s;
    int temp;

    for (int i = s; i < e; i++)
    {
        if (v[i] <= pivot)
        {
            temp = v[i];
            v[i] = v[index];
            v[index] = temp;
            index++;
        }
    }
    temp = v[index];
    v[index] = pivot;
    v[e] = temp;
    return index;
}
void Quicksort(std::vector<int> &v, int start, int end)
{
    if (start < end)
    {
        int Pindex;
        Pindex = Partiond(v, start, end);
        Quicksort(v, start, Pindex - 1);
        Quicksort(v, Pindex + 1, end);
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
    // SelectionSort(v);
    // bubblesort(v);
    insertionSort(v);
    // MergeSort(v);
    // Quicksort(v, 0, n - 1);
    print(v);
    return 0;
}
