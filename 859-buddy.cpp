#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  bool buddyStrings(string s, string goal)
  {
    if (s.size() != goal.size())
    {
      return false;
    }

    int letterCount[30] = {};
    vector<int> diffs;

    bool hasRepeat = false;
    for (int i = 0; i < s.size(); i++)
    {
      if (!hasRepeat)
      {
        letterCount[s[i] - 'a']++;
        if (letterCount[s[i] - 'a'] >= 2)
        {
          hasRepeat = true;
        }
      }

      if (s[i] != goal[i])
      {
        diffs.push_back(i);
      }
    }

    if (diffs.size() == 0 && hasRepeat)
    {
      return true;
    }

    if (diffs.size() != 2)
    {
      return false;
    }

    return s[diffs[0]] == goal[diffs[1]] && s[diffs[1]] == goal[diffs[0]];
  }
};
