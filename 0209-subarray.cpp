// g++ -std=c++11 0209-subarray.cpp -o app && ./app
// leet uses c++11

#include <vector>

using namespace std;

class Solution
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int s = 0;
    int sum = nums[0];
    int minLen = 999999999;
    if (sum >= target)
    {
      return 1;
    }

    for (int i = 1; i < nums.size(); i++)
    {
      auto curr = nums[i];
      if (curr >= target)
      {
        return 1;
      }

      sum += curr;
      while (sum - nums[s] >= target)
      {
        sum -= nums[s];
        s++;
      }

      if (sum >= target)
      {
        minLen = min(minLen, i - s + 1);
      }
    }

    if (minLen == 999999999) {
      return 0;
    }
    return minLen;
  }
};

#include "./utils/assert.cpp"

int main()
{
  vector<int> strs1 = {2, 3, 1, 2, 4, 3};
  assertTrue((new Solution())->minSubArrayLen(7, strs1), 2);

  vector<int> strs2 = {1, 1, 1, 1, 1, 2, 2, 2};
  assertTrue((new Solution())->minSubArrayLen(5, strs2), 3);

  vector<int> strs3 = {1, 1, 1, 1, 1, 2, 2, 2, 4};
  assertTrue((new Solution())->minSubArrayLen(5, strs3), 2);
}
