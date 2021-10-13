#include <vector>
#include <cstdlib>
using namespace std;

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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return nullptr;
        TreeNode *root;
        root = (TreeNode *)malloc(sizeof(TreeNode));
        root->val = preorder[0];
        if (preorder.size() == 1)
            return root;
        vector<int> left, right;
        for (auto i = 1; i != preorder.size(); i++)
        {
            if (root->val > preorder[i])
            {
                left.push_back(preorder[i]);
            }
            else
            {
                right.push_back(preorder[i]);
            }
        }
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};