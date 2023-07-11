#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
  {
    vector<int> ans;
    if (root == nullptr || target == nullptr)
    {
      return ans;
    }

    TreeNode *parent[500] = {};
    int dists[500] = {};
    bool vis[500] = {};

    queue<TreeNode *> nodeQ;
    nodeQ.push(root);
    while (nodeQ.size() > 0)
    {
      auto cNode = nodeQ.front();
      nodeQ.pop();
      if (cNode->left != nullptr)
      {
        parent[cNode->left->val] = cNode;
        nodeQ.push(cNode->left);
      }
      if (cNode->right != nullptr)
      {
        parent[cNode->right->val] = cNode;
        nodeQ.push(cNode->right);
      }
    }

    nodeQ.push(target);
    dists[target->val] = 0;
    while (nodeQ.size() > 0)
    {
      auto cNode = nodeQ.front();
      nodeQ.pop();
      auto dist = dists[cNode->val];

      if (vis[cNode->val])
      {
        continue;
      }
      vis[cNode->val] = true;

      if (dist == k)
      {
        ans.push_back(cNode->val);
        continue;
      }

      if (dist > k)
      {
        continue;
      }

      if (cNode->left != nullptr)
      {
        nodeQ.push(cNode->left);
        dists[cNode->left->val] = dist + 1;
      }

      if (cNode->right != nullptr)
      {
        nodeQ.push(cNode->right);
        dists[cNode->right->val] = dist + 1;
      }

      if (parent[cNode->val] != nullptr)
      {
        nodeQ.push(parent[cNode->val]);
        dists[parent[cNode->val]->val] = dist + 1;
      }
    }

    return ans;
  }
};
