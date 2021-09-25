#include <iostream>

using std::cout;
struct node
{
    float value;
    node *left = nullptr;
    node *right = nullptr;
};
class Binary_Search_Tree
{
    node *root;

protected:
    void display_preOrder(node *n)
    {
        if (n == nullptr)
        {
            return;
        }
        cout << n->value << " ";
        display_preOrder(n->left);
        display_preOrder(n->right);
    }
    void display_inOrder(node *n)
    {
        if (n == nullptr)
        {
            return;
        }
        display_inOrder(n->left);
        cout << n->value << " ";
        display_inOrder(n->right);
    }
    void display_postOrder(node *n)
    {
        if (n == nullptr)
        {
            return;
        }
        display_postOrder(n->left);
        display_postOrder(n->right);
        cout << n->value << " ";
    }

public:
    Binary_Search_Tree()
    {
        root = nullptr;
    }
    void add(node &n)
    {
        node *itr = root;
        if (itr == nullptr)
        {
            root = &n;
            return;
        }
        while (itr != nullptr)
        {
            if (itr->value > n.value)
            {
                if (itr->left == nullptr)
                {
                    itr->left = &n;
                    break;
                }
                itr = itr->left;
            }
            else if (itr->value < n.value)
            {
                if (itr->right == nullptr)
                {
                    itr->right = &n;
                    break;
                }
                itr = itr->right;
            }
        }
    }
    void display(int fn)
    {
        switch (fn)
        {
        case 1:
            display_preOrder(root);
            cout << "\n PRE ORDER";
            printf("\n");
            break;
        case 2:
            display_inOrder(root);
            cout << "\n IN OREDER";
            printf("\n");
            break;
        case 3:
            display_postOrder(root);
            cout << "\n POST ORDER";
            std::cout << std::endl;
            break;
        default:
            break;
        }
    }
    void find(float x)
    {
        node *itr;
        itr = root;
        while (itr != nullptr)
        {
            if (itr->value == x)
            {
                cout << "\n FOUND";
                return;
            }
            else if (itr->value > x)
            {
                itr = itr->left;
            }
            else
            {
                itr = itr->right;
            }
        }
        if (itr == nullptr)
        {
            cout << "\nNOT FOUND";
        }
    }
};
int main()
{
    using namespace std;
    Binary_Search_Tree bst;

    int a = 0;
    while (a != -1)
    {
        cout << "\n1 to add\n2 to find\n3 to print\n4 to find element at k\n5 to pop\n6 add in poistion\n7 delete the position \n-1 to quit ";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "\nenter to add: ";
            node *y = new node;
            cin >> y->value;
            bst.add(*y);
            break;
        }
        case 2:
        {
            float x;
            cout << "enter element to be found: ";
            cin >> x;
            bst.find(x);
            break;
        }
        case 3:
        {
            cout << "\n";
            cout << "\n";
            bst.display(1);
            cout << "\n";
            bst.display(2);
            cout << "\n";
            bst.display(3);
            cout << "\n";
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
