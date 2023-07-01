#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    bool isEven = (nums1.size() + nums2.size()) % 2 == 0;
    int halfCount = (nums1.size() + nums2.size()) / 2;
    
    double lo = min((nums1.size() > 0 ? nums1[0] : nums2[0]), (nums2.size() > 0 ? nums2[0] : nums1[0]));
    double hi = max((nums1.size() > 0 ? nums1[nums1.size() - 1] : nums2[nums2.size() - 1]), (nums2.size() > 0 ? nums2[nums2.size() - 1] : nums1[nums1.size() - 1]));

    while (true) {
      double pivot = (lo + hi) / 2.0;
      if (lo == hi) { return pivot; }

      auto lower1 = lower_bound(nums1.begin(), nums1.end(), pivot);
      auto lower2 = lower_bound(nums2.begin(), nums2.end(), pivot);

      int idx1 = distance(nums1.begin(), lower1);
      int idx2 = distance(nums2.begin(), lower2);
      int lowerTotal = idx1 + idx2;

      if (lowerTotal == halfCount) {
        int right1 = lower1 != nums1.end() ? *lower1 : *lower2;
        int right2 = lower2 != nums2.end() ? *lower2 : *lower1;
        int right = min(right1, right2);

        if (!isEven) { return right; }

        int left1 = idx1 > 0 ? *prev(lower1) : *prev(lower2);
        int left2 = idx2 > 0 ? *prev(lower2) : *prev(lower1);
        int left = max(left1, left2);

        return (left + right) / 2.0;
      } else if (lowerTotal < halfCount) {
        lo = ceil(pivot);
      } else {
        hi = floor(pivot);
      }
    }
  }
};

void test(double expected, const vector<int>& nums1, const vector<int>& nums2) {
  Solution* s = new Solution();
  double result = s->findMedianSortedArrays(nums1, nums2);
  if (abs(result - expected) > 0.00001) {
    std::cout << "expected: " << expected << " but got: " << result << "\n";
  }
}

int main() {
  test(2, {1,3}, {2});
  test(2.5, {1,3}, {2,4});
  test(3, {1,3,5}, {2,4});
  test(3.5, {1,3,5}, {2,4,6});
  test(3.5, {1}, {2,3,4,5,6});
  test(1, {1}, {});
  test(1, {}, {1});
  test(0, {0,0}, {0,0});
  test(0,{0,0,0,0,0},{-1,0,0,0,0,0,1});
  test(6,{4,5,6,8,9},{});
  test(1.5,{1,2},{-1,3});
  return 0;
}
