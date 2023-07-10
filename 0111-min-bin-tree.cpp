// g++ -std=c++11 0111-min-bin-tree.cpp -o app && ./app
// leet uses c++11

#include <algorithm>

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
  int _depth(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 1e7;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
      return 0;
    }

    return 1 + min(this->_depth(root->left), this->_depth(root->right));
  }

  int minDepth(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }

    return 1 + this->_depth(root);
  }
};

int main()
{
  return 0;
}
