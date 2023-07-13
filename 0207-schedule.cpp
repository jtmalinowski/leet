// g++ -std=c++11 0207-schedule.cpp -o app && ./app
// leet uses c++11

#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    map<int, vector<int>> dests;

    for (auto w : prerequisites)
    {
      dests[w[0]].push_back(w[1]);
    }

    vector<int> steps;
    for (int i = 0; i < numCourses; i++)
    {
      if (dests.count(i) > 0)
      {
        steps.push_back(i);
      }
    }

    bool gray[2000] = {};
    bool black[2000] = {};

    while (steps.size() > 0)
    {
      auto curr = steps.back();

      if (black[curr])
      {
        steps.pop_back();
        continue;
      }

      if (gray[curr])
      {
        black[curr] = true;
        steps.pop_back();
        continue;
      }

      gray[curr] = true;

      if (dests.count(curr) == 0)
      {
        continue;
      }

      for (auto d : dests[curr])
      {
        if (black[d])
        {
          continue;
        }
        if (gray[d])
        {
          return false;
        }
        steps.push_back(d);
      }
    }

    return true;
  }
};

#include "./utils/assert.cpp"

int main()
{
  vector<vector<int>> p1 = {{1, 0}, {2, 1}};
  assertEq((new Solution())->canFinish(3, p1), true);

  vector<vector<int>> p2 = {{100, 0}, {1999, 100}};
  assertEq((new Solution())->canFinish(2000, p2), true);

  vector<vector<int>> p3 = {{100, 0}, {1999, 101}};
  assertEq((new Solution())->canFinish(2000, p3), true);

  vector<vector<int>> p4 = {{3, 2}, {3, 1}, {2, 0}, {1, 0}};
  assertEq((new Solution())->canFinish(3, p4), true);

  vector<vector<int>> p5 = {{3, 2}, {3, 1}, {2, 0}, {1, 0}, {0, 3}};
  assertEq((new Solution())->canFinish(4, p5), false);
}
