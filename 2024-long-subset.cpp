#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxCAns(string &answerKey, int k, char T, char F)
  {
    int winS = 0;
    int maxTs = (answerKey[0] == T) ? 1 : 0;
    int usedKs = (answerKey[0] == F) ? 1 : 0;

    for (int i = 1; i < answerKey.size(); i++)
    {
      if (answerKey[i] == T)
      {
      }
      else
      {
        if (usedKs < k)
        {
          usedKs++;
        }
        else
        {
          // remove first k op on or after winS
          for (int j = winS;; j++)
          {
            if (answerKey[j] == T)
            {
              continue;
            }
            winS = j + 1;
            break;
          }
        }
      }

      maxTs = max(maxTs, i - winS + 1);
    }

    return maxTs;
  }

  int maxConsecutiveAnswers(string answerKey, int k)
  {
    return max(maxCAns(answerKey, k, 'T', 'F'), maxCAns(answerKey, k, 'F', 'T'));
  }
};
