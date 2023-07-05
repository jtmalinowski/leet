// g++ -std=c++11 0955-delete-columns.cpp -o app && ./app
// leet uses c++11

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>

using namespace std;

const int IDX_GUARD = 9999999;

class Solution
{
public:
  void compare(vector<string> &strs, set<int> &dels)
  {

    vector<pair<int, int>> eqs = {{0, strs.size()}};
    vector<pair<int, int>> nextEqs;

    int col = 0;

    while (col < strs[0].size() && eqs.size() > 0)
    {
      nextEqs = {};
      for (auto eq : eqs)
      {

        for (int idx = eq.first + 1; idx < eq.second; idx++)
        {
          if (strs[idx][col] < strs[idx - 1][col])
          {
            dels.insert(col);
            goto next_col;
            break;
          }
        }

        int eqS = IDX_GUARD;
        for (int idx = eq.first + 1; idx < eq.second; idx++)
        {
          if (strs[idx][col] == strs[idx - 1][col])
          {
            eqS = min(eqS, idx - 1);
          }
          else
          {
            if (eqS != IDX_GUARD)
            {
              nextEqs.push_back({eqS, idx});
              eqS = IDX_GUARD;
            }
          }
        }
        if (eqS != IDX_GUARD)
        {
          nextEqs.push_back({eqS, eq.second});
        }
      }
      eqs = nextEqs;

    next_col:
      col++;
    }
  }

  int minDeletionSize(vector<string> &strs)
  {
    set<int> dels;
    compare(strs, dels);
    return dels.size();
  }
};

#include "./utils/assert.cpp"

int main()
{
  vector<string> strs1 = {"xa", "wb"};
  assertTrue((new Solution())->minDeletionSize(strs1), 1);

  vector<string> strs2 = {"ca", "bb", "ac"};
  assertTrue((new Solution())->minDeletionSize(strs2), 1);

  vector<string> strs3 = {"xc", "yb", "za"};
  assertTrue((new Solution())->minDeletionSize(strs3), 0);
}
