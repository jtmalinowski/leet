// g++ -std=c++11 0894-full-bin-trees.cpp -o app -fsanitize=address -static-libsan -g && ./app
// leet uses c++11

#include <vector>
#include <utility>
#include <iostream>

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
  vector<TreeNode *> allPossibleFBT(int n)
  {
    vector<vector<TreeNode *>> states;

    states.push_back({});
    states.push_back({new TreeNode()});
    states.push_back({});
    states.push_back({new TreeNode(0, new TreeNode(), new TreeNode())});

    while (states.size() <= n)
    {
      auto newGenIdx = states.size();
      vector<TreeNode *> newGen;
      for (int i = 1; i <= newGenIdx - 2; i++)
      {
        for (auto left : states[i])
        {
          for (auto right : states[newGenIdx - i - 1])
          {
            newGen.push_back(new TreeNode(0, left, right));
          }
        }
      }
      states.push_back(newGen);
    }

    return states[n];
  }
};

bool assertEqTree(TreeNode *test, TreeNode *expected)
{
  if (test->val != expected->val)
  {
    return false;
  }

  if (expected->left != nullptr)
  {
    if (test->left == nullptr)
    {
      return false;
    }
    if (!assertEqTree(test->left, expected->left))
    {
      return false;
    }
  }

  if (expected->right != nullptr)
  {
    if (test->right == nullptr)
    {
      return false;
    }
    if (!assertEqTree(test->right, expected->right))
    {
      return false;
    }
  }

  return true;
}

bool assertEqTree(vector<TreeNode *> test, vector<TreeNode *> expected)
{
  if (test.size() != expected.size())
  {
    return false;
  }

  for (int i = 0; i < expected.size(); i++)
  {
    if (!assertEqTree(test[i], expected[i]))
    {
      return false;
    }
  }

  return true;
}

#include "utils/assert.cpp"

int main()
{
  assertEq((new Solution())->allPossibleFBT(7).size(), 5);
}
