#include <iostream>
#include <cmath>

struct node
{
    float value;
    node *left = nullptr;
    node *right = nullptr;
    int height = 1;
};

class AVL
{
    node *base;

protected:
    int height(node *N)
    {
        if (N == nullptr)
            return 0;
        return N->height;
    }
    int getBalance(node *N)
    {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    node *leftRotate(node *root)
    {
        node *n_r = root->right;
        node *n_r_l = n_r->left;

        // Perform rotation
        n_r->left = root;
        root->right = n_r_l;

        // Update heights
        root->height = std::max(height(root->left), height(root->right)) + 1;
        n_r->height = std::max(height(n_r->left), height(n_r->right)) + 1;

        // Return new root
        return n_r;
    }
    node *rightRotate(node *n)
    {
        node *n_l = n->left;
        node *n_l_r = n_l->right;

        n_l->right = n;
        n->left = n_l_r;

        // Update heights
        n->height = std::max(height(n->left), height(n->right)) + 1;
        n_l->height = std::max(height(n_l->left), height(n_l->right)) + 1;

        // Return new root
        return n_l;
    }

    node *insert(node *root, float val)
    {
        if (root == nullptr)
        {
            node *n = new node;
            n->value = val;
            return n;
        }
        else if (root->value < val)
        {
            root->right = insert(root->right, val);
        }
        else if (val < root->value)
        {
            root->left = insert(root->left, val);
        }
        else
        {
            return root;
        }
        //this was simple bst insert

        //now calculating the height of each node that has changed
        root->height = std::max(height(root->left), height(root->right)) + 1;

        int balance = getBalance(root);
        if (balance < -1 && val > root->right->value) //the balance is being calculated as L-R so if the balance is -ve it means the bst is R heavy and we need to do a leftRotation and more over only leftRotation if the element that we inserted is aslo on the right
        {
            return leftRotate(root);
        }
        if (balance > 1 && root->left->value > val)
        {
            return rightRotate(root);
        }
        if (balance < -1 && root->right->value > val)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        if (balance > 1 && root->left->value < val)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        return root;
    }
    void preOrder(node *root)
    {
        if (root != NULL)
        {
            std::cout << root->value << ":" << root->height << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

public:
    AVL()
    {
        base = nullptr;
    }
    void ins(float x)
    {
        base = insert(base, x);
    }
    void display()
    {
        preOrder(base);
    }
};

int main()
{
    using namespace std;

    AVL avl;
    avl.ins(1);
    avl.ins(5);
    avl.ins(6);
    avl.ins(7);
    avl.ins(8);
    avl.ins(9);
    avl.ins(10);
    avl.ins(6.7);
    avl.display();
    return 0;
}
