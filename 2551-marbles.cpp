// g++ -std=c++11 2551-marbles.cpp -o app -fsanitize=address -static-libsan -g && ./app
// leet uses c++11

#include <string>
#include <set>
#include <numeric>

using namespace std;

class Solution
{
public:
  long long putMarbles(vector<int> &weights, int k)
  {
    if (k == 1)
    {
      return 0;
    }

    int sumsL = k - 1;

    vector<long long> sums;
    for (int i = 0; i < weights.size() - 1; i++)
    {
      sums.push_back(weights[i] + weights[i + 1]);
    }
    sort(sums.begin(), sums.end());

    long long minS = weights[0] + *weights.rbegin();
    long long maxS = minS;

    minS += accumulate(sums.begin(), sums.begin() + k - 1, 0LL);
    maxS += accumulate(sums.begin() + sums.size() - k + 1, sums.end(), 0LL);

    return maxS - minS;
  }
};

#include "./utils/assert.cpp"

int main()
{
  vector<int> w1 = {1,3,5,1};
  assertEq((new Solution())->putMarbles(w1, 2), 4);

  vector<int> w2 = {1,3};
  assertEq((new Solution())->putMarbles(w2, 2), 0);

  vector<int> w3 = {1,2,3,4,5,6,7,8,9};
  assertEq((new Solution())->putMarbles(w3, 2), 14);
}
