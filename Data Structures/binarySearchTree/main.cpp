#include<iostream>
#include "./node.h"

void printbst(node* root) {
    if (root != nullptr) {
        printbst(root->left);
        std::cout << root->val << " -> ";
        printbst(root->right);
    }

}


int main() {
    int ele;
    node* root = nullptr;
    node** rootptr = &root;
    std::cout << "enter elements to be added to tee : \n";
    while (std::cin >> ele) {
        // newnode.insertnode(rootptr,ele,root);
        node node(&root, ele, *rootptr);
    }
    printbst(root);
    node newnode;
    newnode.deletenode(10, root, *rootptr);
    std::cout << std::endl;
    printbst(root);
    return 0;
}
