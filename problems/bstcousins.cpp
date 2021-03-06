#include <iostream>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int xDepth = -1;
    int yDepth = -1;
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root->val == x || root->val == y)
            return 0;
        else
        {
        traversetree(root, x,y,0);
        return xDepth != -1 && xDepth == yDepth;
        }
    }
    void traversetree(TreeNode *root, int x,int y,int depth)
    {
        if(!root) return;
        if(
            root->left &&
            root->right && 
            (root->left->val == x || root->left->val == y) &&
            (root->right->val == x || root->right->val == y)
        ) return;

        if(root->val == x){
            xDepth = depth;
            return;
        }
        if(root->val == y){
            yDepth = depth;
            return;
        }
        solve(root->left, x, y, depth+1);
        solve(root->right, x, y, depth+1);
    }
};