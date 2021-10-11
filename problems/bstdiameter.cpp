 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root)
{
  if (root == nullptr)
    return 0;
  int dia = 0;
  traversetree(root, dia);
  return dia;
}

std::pair<int, int> traversetree(TreeNode *root, int &dia)
{
  if (root == nullptr)
    return {0, 0};
  std::pair<int, int> l, r;
  l = traversetree(root->left, dia);
  r = traversetree(root->right, dia);
  int newdist = std::max(l.first, l.second) + std::max(r.first, r.second) ;
  dia = std::max(dia,newdist);
  return {std::max(l.first, l.second) + 1, std::max(r.first, r.second) + 1};
}
};