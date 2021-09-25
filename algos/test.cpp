#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left = nullptr;
    node *right = nullptr;
};
bool helper(node *T1, node *T2)
{
    if (T2 == nullptr)
        return 1;
    if (T1 == nullptr && T2 != nullptr)
        return 0;

    if (T1->val != T2->val)
        return 0;
    return helper(T1->left, T2->left) && helper(T1->right, T2->right);
}
bool isSubTree(node *T1, node *T2)
{
    if (T2 == nullptr)
        return 1;
    if (T1 == nullptr && T2 != nullptr)
        return 0;

    return helper(T1, T2) || (isSubTree(T1->left, T2) || isSubTree(T1->right, T2));
}
int main()
{
    using namespace std;
    node *root = new node;
    root->val = 1;
    node *L = new node;
    L->val = 2;
    node *R = new node;
    R->val = 3;
    root->left = L;
    root->right = R;

    node *root2 = new node;
    root2->val = 1;
    node *L2 = new node;
    L2->val = 3;
    root2->left = L2;
    std::cout << isSubTree(root, root2);
    return 0;
}