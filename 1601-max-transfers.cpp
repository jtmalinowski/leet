#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maximumRequests(int n, vector<vector<int>> &requests)
  {
    int base = 0;
    int maxSum = -1;

    int toDeg[20] = {};
    int fromDeg[20] = {};
    for (auto req : requests)
    {
      toDeg[req[1]]++;
      fromDeg[req[0]]++;
    }

    vector<vector<int>> validReqs;
    for (int i = 0; i < requests.size(); i++)
    {
      if (requests[i][0] == requests[i][1])
      {
        base++;
        continue;
      }

      auto req = requests[i];
      if (toDeg[req[0]] == 0)
      {
        continue;
      }
      if (fromDeg[req[1]] == 0)
      {
        continue;
      }

      validReqs.push_back(requests[i]);
    }

    int perms = (1 << validReqs.size()) - 1;
    for (int i = 0; i <= perms; i++)
    {
      int sum = 0;
      int ins[20] = {};
      int outs[20] = {};

      for (int j = 0; j < validReqs.size(); j++)
      {
        if (((1 << j) & i) == 0)
        {
          continue;
        }
        outs[validReqs[j][0]]++;
        ins[validReqs[j][1]]++;
        sum++;
      }

      for (int j = 0; j < n; j++)
      {
        if (outs[j] != ins[j])
        {
          sum = -1;
          break;
        }
      }

      maxSum = max(maxSum, sum);
    }

    return base + maxSum;
  }
};
