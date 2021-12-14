#include <iostream>
#include <algorithm>
#include <queue>

class node
{
public:
     int data;
     node *left;
     node *right;

     node(int d)
     {
          data = d;
          left = nullptr;
          right = nullptr;
     }
};

node *create_tree()
{
     int d;
     std::cin >> d;
     if (d == -1)
          return nullptr;
     node *root = new node(d);
     root->left = create_tree();
     root->right = create_tree();
     return root;
}

void print_tree(node *root) // in-order print of tree
{
     if (root == nullptr)
          return;
     std::cout << root->data << " ";
     print_tree(root->left);
     print_tree(root->right);
}

int height_of_tree(node *root)
{
     if (root == nullptr)
          return 0;
     int height = std::max(height_of_tree(root->left), height_of_tree(root->right)) + 1;
     return height;
}

void print_kth_level(node *root, int k)
{
     if (root == nullptr)
          return;
     if (k == 1)
          std::cout << root->data << " ";
     print_kth_level(root->left, k - 1);
     print_kth_level(root->right, k - 1);
}

void tree_level_print(node *root)
{
     int h = height_of_tree(root);
     for (int i = 1; i <= h; i++)
     {
          print_kth_level(root, i);
          std::cout << std::endl;
     }
}

void bfs(node *root)
{
     std::queue<node *> q;
     q.push(root);
     q.push(nullptr);
     while (!q.empty())
     {
          node *temp = q.front();
          if (temp == nullptr)
          {
               std::cout << std::endl;
               q.pop();
               if (!q.empty())
                    q.push(nullptr);
          }
          else
          {
               std::cout << temp->data << " ";
               q.pop();
               if (temp->left)
                    q.push(temp->left);
               if (temp->right)
                    q.push(temp->right);
          }
     }
     return;
}

int main()
{
     node *root = create_tree();
     // print_tree(root);
     // int h = height_of_tree(root);
     // std::cout << h;
     // tree_level_print(root);
     bfs(root);
}