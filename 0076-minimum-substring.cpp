// g++ -std=c++11 0076-minimum-substring.cpp -o app -fsanitize=address -static-libsan -g && ./app
// leet uses c++11

#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

int getRef(char c) {
  return (c >= 'a') ? (c - 'a' + 26) : (c - 'A');
}

class Solution
{
public:
  string minWindow(string s, string t)
  {
    int tChars[52] = {};
    set<char> tCharsSet;
    for (auto c : t) {
      tChars[getRef(c)]++;
      tCharsSet.insert(c);
    }

    int winSChars[52] = {};
    set<char> winCharsSet;
    int winS = 0;
    pair<int,int> bestSub = {0,s.size()};

    for (int i = 0; i < s.size(); i++) {
      auto c = s[i];

      auto ref = getRef(c);
      winSChars[ref]++;

      if (winSChars[ref] == tChars[ref]) {
        // we compare sets and sets don't have duplicates, so only add to the set if we have enough duplicates
        winCharsSet.insert(c);
      }

      if (winCharsSet.size() < tCharsSet.size()) {
        continue;
      }

      while (true) {
        auto remRef = getRef(s[winS]);
        if (winSChars[remRef] - 1 < tChars[remRef]) {
          break;
        }

        winSChars[remRef]--;
        winS++;
      }

      if ((i - winS) < (bestSub.second - bestSub.first)) {
        bestSub = {winS, i};
      } 

    }

    if (bestSub.second == s.size()) {
      return "";
    }

    string res = "";
    for (int i = bestSub.first; i <= bestSub.second; i++) {
      res += (s[i]);
    }
    return res;
  }
};

#include "./utils/assert.cpp"

int main()
{
  assertEq((new Solution())->minWindow("a", "a"), "a");
  assertEq((new Solution())->minWindow("a", "aa"), "");
  assertEq((new Solution())->minWindow("xaxbxcx", "abc"), "axbxc");
  assertEq((new Solution())->minWindow("axbcax", "abc"), "bca");
  assertEq((new Solution())->minWindow("ADOBECODEBANC", "ABC"), "BANC");
  assertEq((new Solution())->minWindow("azAZ", "azAZ"), "azAZ");
}
