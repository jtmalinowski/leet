// g++ -std=c++11 1493-ones.cpp -o app && ./app
// leet uses c++11

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>

using namespace std;

class Solution
{
public:
  int longestSubarray(vector<int> &nums)
  {
    int start = -1;
    int brk = -1;
    int longest = 0;
    bool hasZero = false;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
      {
        hasZero = true;

        if (start == -1)
        {
          continue;
        }

        if (brk == i - 1)
        {
          start = -1;
          brk = -1;
          continue;
        }

        if (brk == -1)
        {
          brk = i;
          continue;
        }

        start = brk + 1;
        brk = i;
        continue;
      }

      if (start == -1)
      {
        start = i;
      }

      longest = max(longest, i - start + 1 + (brk == -1 ? 0 : -1));
    }

    return longest + ((hasZero || longest == 0) ? 0 : -1);
  }
};

#include "./utils/assert.cpp"

int main()
{
  vector<int> nums1 = {0};
  assertTrue((new Solution())->longestSubarray(nums1), 0);

  vector<int> nums2 = {1};
  assertTrue((new Solution())->longestSubarray(nums2), 0);

  vector<int> nums3 = {1, 0};
  assertTrue((new Solution())->longestSubarray(nums3), 1);

  vector<int> nums4 = {0, 1};
  assertTrue((new Solution())->longestSubarray(nums4), 1);

  vector<int> nums5 = {1, 0, 1};
  assertTrue((new Solution())->longestSubarray(nums5), 2);

  vector<int> nums6 = {1, 0, 1, 0, 1};
  assertTrue((new Solution())->longestSubarray(nums6), 2);

  vector<int> nums7 = {1, 1, 0, 1, 1, 0, 0, 1};
  assertTrue((new Solution())->longestSubarray(nums7), 4);

  vector<int> nums8 = {1, 0, 0, 0, 0, 0, 1};
  assertTrue((new Solution())->longestSubarray(nums8), 1);

  vector<int> nums9 = {1, 1, 1};
  assertTrue((new Solution())->longestSubarray(nums9), 2);
}
