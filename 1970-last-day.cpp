// g++ -std=c++11 1970-last-day.cpp -o app && ./app
// leet uses c++11

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <set>

using namespace std;

vector<pair<int, int>> dirs = {
    {0, 1},
    {-1, 1},
    {-1, 0},
    {-1, -1},
    {0, -1},
    {1, -1},
    {1, 0},
    {1, 1},
};

// 1-based !!
bool validDir(int row, int col, pair<int, int> dir) { return (dir.first >= 1) && (dir.second >= 1) && (dir.first <= row) && (dir.second <= col); }

void dfs(int row, int col, const set<pair<int, int>> &points, vector<pair<int, int>> &path)
{
  path.clear();
  set<pair<int, int>> gray;

  for (int y = 1; y <= row; y++)
  {
    if (points.count({y, 1}) == 1)
    {
      path.push_back({y, 1});
    }
  }

  while (true)
  {
    if (path.size() == 0)
    {
      return;
    }

    auto curr = path[path.size() - 1];
    if (curr.second == col)
    {
      return;
    }

    gray.insert(curr);

    for (auto dir : dirs)
    {
      pair<int, int> nxt = {curr.first + dir.first, curr.second + dir.second};
      if (!validDir(row, col, nxt) || gray.count(nxt) > 0 || points.count(nxt) == 0)
      {
        continue;
      }

      path.push_back(nxt);
      break;
    }
    if (path[path.size() - 1] != curr)
    {
      continue;
    }

    // no progress possible, backtrack
    path.pop_back();
  }
}

class Solution
{
public:
  int latestDayToCross(int row, int col, const vector<vector<int>> &cells)
  {
    set<pair<int, int>> points;
    vector<pair<int, int>> path;

    dfs(row, col, points, path);

    int lo = 0;
    int hi = cells.size();
    while (true)
    {
      int pivot = (lo + hi) / 2;
      if (lo == hi)
      {
        return pivot;
      }

      points.clear();
      for (int i = 0; i < pivot; i++)
      {
        points.insert({cells[i][0], cells[i][1]});
      }

      dfs(row, col, points, path);

      if (path.size() > 0)
      {
        hi = pivot;
      }
      else
      {
        if (lo + 1 == hi)
        {
          return lo;
        }
        lo = pivot;
      }
    }
  }
};

void test(int expected, int row, int col, const vector<vector<int>> &cells)
{
  int result = (new Solution())->latestDayToCross(row, col, cells);
  if (result - expected != 0)
  {
    std::cout << "expected: " << expected << " but got: " << result << "\n";
  }
}

int main()
{
  test(2, 2, 2, {{1, 1}, {2, 1}, {1, 2}, {2, 2}});
  test(1, 2, 2, {{1, 1}, {1, 2}, {2, 1}, {2, 2}});
  test(3, 3, 3, {{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}, {1, 3}, {2, 3}, {3, 2}, {3, 1}});
  test(4, 5, 5, {{1, 1}, {1, 2}, {1, 4}, {1, 5}, {1, 3}});
  test(6, 5, 5, {{1, 1}, {1, 2}, {1, 4}, {1, 5}, {2, 2}, {2, 4}, {3, 3}});
}
