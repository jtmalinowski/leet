// g++ -std=c++11 864-all-keys.cpp -o app && ./app
// leet uses c++11

#include <set>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

struct Path
{
  int steps;
  pair<int, int> pos;
  int mask;
};

vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution
{
public:
  int shortestPathAllKeys(vector<string> &grid)
  {
    int maxY = grid.size();
    int maxX = grid[0].size();

    int startX, startY;
    int allKeys = 0;
    for (int y = 0; y < maxY; y++)
    {
      for (int x = 0; x < maxX; x++)
      {
        if (grid[y][x] == '@')
        {
          startX = x;
          startY = y;
        }
        if (grid[y][x] >= 'A' && grid[y][x] <= 'F')
        {
          allKeys++;
        }
      }
    }

    int allKeysMask = (1 << allKeys) - 1;

    queue<Path> paths;
    set<vector<int>> black = {{startY, startX, 0}};
    pair<int, int> spos(startY, startX);
    paths.push(Path{0, spos, 0});

    while (!paths.empty())
    {
      Path path = paths.front();
      paths.pop();
      int y = path.pos.first;
      int x = path.pos.second;

      for (auto d : dirs)
      {
        int cy = y + d.first;
        if (cy < 0 || cy >= maxY)
        {
          continue;
        }

        int cx = x + d.second;
        if (cx < 0 || cx >= maxX)
        {
          continue;
        }

        int cmask = path.mask;
        if (black.count({cy, cx, cmask}) > 0)
        {
          continue;
        }
        if (grid[cy][cx] == '#')
        {
          continue;
        }

        int csteps = path.steps + 1;

        if (grid[cy][cx] >= 'a' && grid[cy][cx] <= 'f')
        {
          cmask |= 1 << (grid[cy][cx] - 'a');
          if ((cmask & allKeysMask) == allKeysMask)
          {
            return csteps;
          }
        }

        if (grid[cy][cx] >= 'A' && grid[cy][cx] <= 'F')
        {
          if (((1 << (grid[cy][cx] - 'A')) & cmask) == 0)
          {
            continue;
          }
        }

        black.insert({cy, cx, cmask});
        paths.push(Path{csteps, {cy, cx}, cmask});
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
