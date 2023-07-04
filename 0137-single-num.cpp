// g++ -std=c++11 0137-single-num.cpp -o app && ./app
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
  int singleNumber(vector<int> &nums)
  {
    const int intSize = 32;
    int bits[intSize] = {};

    for (auto num : nums)
    {
      for (int i = 0; i < intSize; i++)
      {
        if (((num >> i) & 1) > 0)
        {
          bits[i]++;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < intSize; i++)
    {
      bits[i] %= 3;
      if (bits[i] > 0)
      {
        ans |= (1 << i);
      }
    }
    return ans;
  }
};

#include "./utils/assert.cpp"

int main() {
  vector<int> nums1 = {-2,-2,1,1,4,1,4,4,-4,-2};
  assertTrue((new Solution())->singleNumber(nums1), -4);

  vector<int> nums2 = {INT_MIN, INT_MAX, INT_MAX, INT_MAX};
  assertTrue((new Solution())->singleNumber(nums2), INT_MIN);

  vector<int> nums3 = {INT_MAX, INT_MIN, INT_MIN, INT_MIN};
  assertTrue((new Solution())->singleNumber(nums3), INT_MAX);
}
