// g++ -std=c++11 0956-tallest-billboard.cpp -o app && ./app
// leet uses c++11

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>

using namespace std;

bool descending(int i, int j) { return (i > j); }

class Solution
{
public:
  int tallestBillboard(vector<int> &rods)
  {
    int maxVs[5100];
    fill_n(maxVs, 5100, -1e6);
    maxVs[0] = 0;

    int sum = accumulate(rods.begin(), rods.end(), 0);

    for (auto rod : rods)
    {
      int prevMaxVs[5100];
      copy(maxVs, maxVs + sum + 1, prevMaxVs);

      for (int i = 0; i <= (sum - rod); i++)
      {
        maxVs[i + rod] = max(prevMaxVs[i] + rod, maxVs[i + rod]);
        maxVs[abs(i - rod)] = max(prevMaxVs[i] + rod, maxVs[abs(i - rod)]);
      }
    }

    return maxVs[0] / 2;
  }
};

int main()
{
  auto s = new Solution();

  vector<int> t1 = {1, 2, 3, 6};
  assert(s->tallestBillboard(t1) == 6);

  vector<int> t2 = {1, 2, 3, 4, 5, 6};
  assert(s->tallestBillboard(t2) == 10);

  vector<int> t3 = {1, 2};
  assert(s->tallestBillboard(t3) == 0);

  vector<int> t4 = {2, 4, 8, 16};
  assert(s->tallestBillboard(t4) == 0);

  vector<int> t5 = {16, 8, 4, 2};
  assert(s->tallestBillboard(t5) == 0);
}
