#pragma once
//#include <iostream>

class node
{
public:
    int val;
    node* left;
    node* right;
    node();
    node(node** l, int val, node* parent);
   // node* traverse(node* root);
   // std::pair<int, int> findmaxandmin(node* root);
   // void printbst(node* root);
    void insertnode(node** l, int val, node* parent);
    void deletenode(int val, node* root, node* parent);
    node* findsuccessor(node* root);
};

