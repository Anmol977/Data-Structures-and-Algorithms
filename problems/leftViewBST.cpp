#include <iostream>
#include <vector>

class node
{
public:
    node *left;
    node *right;
    int val;

    node(int data)
    {
        this->val = data;
        this->left = this->right = nullptr;
    }
};

node *insert_node(int val, node *root)
{
    if (root == nullptr)
    {
        return new node(val);
    }
    else
    {
        if (root->val < val)
        {
            root->right = insert_node(val, root->right);
        }
        else
        {
            root->left = insert_node(val, root->left);
        }
    }
    return root;
}

node *build()
{
    int val;
    std::cin >> val;
    node *root = nullptr;
    while (val != -1)
    {
        root = insert_node(val, root);
        std::cin >> val;
    }
    return root;
}

void print_tree(node *root)
{
    if (root == nullptr)
        return;
    print_tree(root->left);
    std::cout << root->val << ", ";
    print_tree(root->right);
}

void print_left_tree(node *root,node *bst_root)
{
    if(root == nullptr)
        return;
    print_left_tree(root->left, root);
    std::cout<<root->val<<" ";
    if(root == bst_root){
        return;
    }
    print_left_tree(root->right, root);
}

int main()
{
    node *root = build();
    // print_tree(root);
    // std::cout<<std::endl;
    print_left_tree(root,root);
}