// g++ -Wall -std=c++11 0673-lis-count.cpp -o app -fsanitize=address -static-libsan -g && ./app

#include <map>
#include <iostream>
#include <format>

#define FMT_HEADER_ONLY
#include </opt/homebrew/include/fmt/format.h>

using namespace std;

class Solution
{
public:
  int findNumberOfLIS(vector<int> &nums)
  {
    vector<pair<int, int>> mem = {{1, 1}};
    if (nums.size() == 1)
    {
      return mem[0].second;
    }

    for (int i = 1; i < nums.size(); i++)
    {
      int maxLen = 1;
      int maxC = 1;

      for (int j = 0; j < i; j++)
      {
        if (nums[j] >= nums[i])
        {
          continue;
        }

        auto len = mem[j].first + 1;
        if (len > maxLen)
        {
          maxLen = len;
          maxC = mem[j].second;
        }
        else if (len == maxLen)
        {
          maxC += mem[j].second;
        }

        // fmt::print("l: {}({}) r: {}({}) maxLen: {} maxC: {} \n", nums[j], j, nums[i], i, maxLen, maxC);
      }

      mem.push_back({maxLen, maxC});
      // fmt::print("i: {}({}) maxLen: {} maxC: {} \n", i, nums[i], maxLen, maxC);
    }

    pair<int, int> res = {0, 0};
    for (auto part : mem)
    {
      if (part.first > res.first)
      {
        res = part;
      }
      else if (part.first == res.first)
      {
        res.second += part.second;
      }
    }

    return res.second;
  }
};

#include "utils/assert.cpp"

int main()
{
  vector<int> n1 = {1, 3, 5, 4, 7, 0, -1000000};
  assertEq((new Solution())->findNumberOfLIS(n1), 2);

  vector<int> n2 = {1, 2, 3, 3, 3, 3, 0, -1000000};
  assertEq((new Solution())->findNumberOfLIS(n2), 4);

  vector<int> n3 = {1, 2, 6, 5, 3, 0, -1000000};
  assertEq((new Solution())->findNumberOfLIS(n3), 3);

  vector<int> n4 = {1, 2, 1, 2, 1, 2, 7, 0, -1000000};
  assertEq((new Solution())->findNumberOfLIS(n4), 6);

  vector<int> n5 = {2, 2, 2, 2, 2, 2, 0, -1000000};
  assertEq((new Solution())->findNumberOfLIS(n5), 8);

  vector<int> n6 = {1, 1, 1, 2, 2, 2, 3, 3, 3};
  assertEq((new Solution())->findNumberOfLIS(n6), 27);
}
