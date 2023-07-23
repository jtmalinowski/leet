// g++ -std=c++11 0688-knight.cpp -o app -fsanitize=address -static-libsan -g && ./app
// leet uses c++11

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

// DFS over dynamic-programming states
// each state is a probability of the knight staying on the board, after k rounds, starting from the given position row:column
// complexity is O(k*n*n)

class Solution
{
private:
  vector<pair<int, int>> dirs = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

  double dfs(double (&steps)[101][26][26], int n, int k, int row, int column)
  {
    if (row < 0 || row >= n || column < 0 || column >= n)
    {
      return -1;
    }

    if (k == 0)
    {
      return 1;
    }

    if (steps[k][row][column] > -1)
    {
      return steps[k][row][column];
    }

    double sum = 0;
    for (auto dir : dirs)
    {
      auto dVal = dfs(steps, n, k - 1, row + dir.first, column + dir.second);
      if (dVal == -1)
      {
        continue;
      }
      sum += dVal;
    }

    auto res = sum / 8.0;
    steps[k][row][column] = res;
    return res;
  }

public:
  double knightProbability(int n, int k, int row, int column)
  {
    double steps[101][26][26];
    for (int d1 = 0; d1 <= k; d1++)
    {
      for (int d2 = 0; d2 < n; d2++)
      {
        for (int d3 = 0; d3 < n; d3++)
        {
          steps[d1][d2][d3] = -1;
        }
      }
    }

    return dfs(steps, n, k, row, column);
  }
};

#include "utils/assert.cpp"

int main()
{
  assertEq((new Solution())->knightProbability(3, 2, 0, 0), 0.0625, 0.0001);

  assertEq((new Solution())->knightProbability(5, 0, 2, 2), 1, 0.0001);
  assertEq((new Solution())->knightProbability(5, 1, 2, 2), 1, 0.0001);
  assertEq((new Solution())->knightProbability(5, 2, 2, 2), 0.375, 0.0001);

  assertEq((new Solution())->knightProbability(9, 2, 4, 4), 1, 0.0001);
  assertEq((new Solution())->knightProbability(9, 3, 4, 4), 0.75, 0.0001);

  return 0;
}
