// g++ -std=c++11 1630-arithmetic-subarrays.cpp -o app -fsanitize=address -static-libsan -g && ./app

#include <set>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

struct Query
{
  int l;
  int r;
  int idx;
};

bool compareQueries(const Query &a, const Query &b)
{
  if (a.l < b.l)
  {
    return true;
  }
  else if (a.l > b.l)
  {
    return false;
  }
  else
  {
    return a.r < b.r;
  }
}

class Solution
{
public:
  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
  {
    vector<Query> queries;
    vector<bool> ans;

    for (int idx = 0; idx < l.size(); idx++)
    {
      queries.push_back(Query{l[idx], r[idx], idx});
      ans.push_back(false); // preset vector
    }
    sort(queries.begin(), queries.end(), compareQueries);

    multiset<int> currNums;
    Query prevQuery = {-1, -1, -1};
    for (int idx = 0; idx < queries.size(); idx++)
    {
      Query currQuery = queries[idx];


      for (int idxRem = prevQuery.l; idxRem < min(currQuery.l, prevQuery.r + 1); idxRem++)
      {
        if (idxRem < 0)
        {
          continue;
        }
        currNums.erase(currNums.find(nums[idxRem]));
      }

      for (int idxRem = prevQuery.r; idxRem > currQuery.r; idxRem--)
      {
        if (idxRem < 0)
        {
          continue;
        }
        currNums.erase(currNums.find(nums[idxRem]));
      }

      for (int idxAdd = max(currQuery.l, prevQuery.r + 1); idxAdd <= currQuery.r; idxAdd++)
      {
        currNums.insert(nums[idxAdd]);
      }

      bool diff_set = false;
      bool prev_set = false;
      bool diff_mismatch = false;
      int diff = 0;
      int prev = 0;

      for (int num : currNums)
      {
        int currDiff = num - prev;

        if (!prev_set)
        {
          prev = num;
          prev_set = true;
          continue;
        }

        if (!diff_set)
        {
          diff = currDiff;
          diff_set = true;
          prev = num;
          continue;
        }

        if (currDiff != diff)
        {
          diff_mismatch = true;
          break;
        }
        prev = num;
      }

      ans[currQuery.idx] = !diff_mismatch;
      prevQuery = currQuery;
    }

    return ans;
  }
};

#include "utils/assert.cpp"

int main()
{
  vector<int> nums1 = {4, 6, 5, 9, 3, 7};
  vector<int> l1 = {0, 0, 2};
  vector<int> r1 = {2, 3, 5};
  assertEq((new Solution())->checkArithmeticSubarrays(nums1, l1, r1), {true, false, true});

  vector<int> nums2 = {-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10};
  vector<int> l2 = {0, 1, 6, 4, 8, 7};
  vector<int> r2 = {4, 4, 9, 7, 9, 10};
  assertEq((new Solution())->checkArithmeticSubarrays(nums2, l2, r2), {false, true, false, false, true, true});
}
