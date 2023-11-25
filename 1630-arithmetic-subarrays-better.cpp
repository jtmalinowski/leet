// g++ -std=c++11 1630-arithmetic-subarrays-better.cpp -o app -fsanitize=address -static-libsan -g && ./app

#include <set>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
  {
    vector<bool> ans;
    bool visited[501] = {0};

    for (int idx = 0; idx < l.size(); idx++)
    {
      int currL = l[idx], currR = r[idx];
      int stepsNo = currR - currL;

      int currMax = INT32_MIN, currMin = INT32_MAX;
      for (int currIdx = currL; currIdx <= currR; currIdx++) {
        currMax = max(currMax, nums[currIdx]);
        currMin = min(currMin, nums[currIdx]);
        visited[currIdx - currL] = 0;
      }

      if (currMax == currMin) {
        ans.push_back(true);
        continue;
      }

      if ((currMax - currMin) % stepsNo != 0) {
        // integer modulo doesn't allow for this to ever be arithmetic
        ans.push_back(false);
        continue;
      }

      int stepVal = (currMax - currMin) / stepsNo;
      bool currAns = true;
      for (int currIdx = currL; currIdx <= currR; currIdx++) {
        int val = nums[currIdx] - currMin;
        
        if (val % stepVal != 0) {
          currAns = false;
          break;
        } 

        visited[val / stepVal] = 1;
      }

      for (int visIdx = 0; (visIdx <= stepsNo) && currAns; visIdx++) {
        if (!visited[visIdx]) {
          currAns = false;
        }
      }

      ans.push_back(currAns);
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
