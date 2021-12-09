#include "node.h"
#include<cstdlib>

// void node::printbst(node *root){
//     printbst(root->left);
//     std::cout<<root->val<<" -> ";
//     printbst(root->right);
// }

node::node() {
    val = 0;
    left = nullptr;
    right = nullptr;
}

node::node(node** l, int val, node* parent)
{
    insertnode(l, val, parent);
}

void node::insertnode(node** l, int val, node* parent)
{
    if (*l == nullptr)
    {
        node *p = (node*)malloc(sizeof(node));
        p->val = val;
        p->left = p->right = nullptr;
        *l = p;
        return;
    }
    else if (val < (*l)->val)
    {
        insertnode(&((*l)->left), val, *l);
    }
    else
        insertnode(&((*l)->right), val, *l);
}

node* node::findsuccessor(node* root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

void node::deletenode(int val, node* root, node* parent)
{
    if (val == root->val)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            if (parent->left == root)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
        else if (!(root->left == nullptr && root->right == nullptr) || (root->left && root->right))
        {
            if (root->left)
            {
                if (parent->left == root)
                    parent->left = root->left;
                else
                    parent->right = root->left;
            }
            else if (root->right)
            {
                if (parent->left == root)
                    parent->left = root->right;
                else
                    parent->right = root->right;
            }
        }
        else
        {
            node* successor = findsuccessor(root->right);
            root->val = successor->val;
            delete (successor);
        }
    }
    else if (val < root->val)
        deletenode(val, (root)->left, root);
    else
        deletenode(val, (root)->right, root);
}