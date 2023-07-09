// g++ -std=c++11 2272-max-variance.cpp -o app -fsanitize=address -static-libsan -g && ./app
// leet uses c++11

#include <string>
#include <set>

using namespace std;

class Solution
{
public:
  template <typename Iter>
  int compute(set<char> &ltrs, Iter start, Iter end)
  {
    if (ltrs.size() == 1)
    {
      return 0;
    }

    int maxLen = 0;
    for (auto c1 : ltrs)
    {
      for (auto c2 : ltrs)
      {
        if (c1 == c2)
          continue;

        int c1s = 0;
        int c2s = 0;

        for (auto iter = start; iter != end; iter++)
        {
          auto c = *iter;
          if (c != c1 && c != c2)
            continue;

          if (c == c1)
          {
            c1s++;
          }
          else
          {
            c2s++;
          }

          if (c2s > c1s)
          {
            c1s = 0;
            c2s = 0;
          }

          if (c1s > 0 && c2s > 0)
          {
            maxLen = max(maxLen, c1s - c2s);
          }
        }
      }
    }
    return maxLen;
  }

  int largestVariance(string s)
  {
    set<char> ltrs;
    for (auto c : s)
    {
      ltrs.insert(c);
    }
    return max(compute(ltrs, s.begin(), s.end()), compute(ltrs, s.rbegin(), s.rend()));
  }
};

#include "./utils/assert.cpp"

int main()
{
  auto s = new Solution;

  assertTrue(s->largestVariance("a"), 0);
  assertTrue(s->largestVariance("aa"), 0);
  assertTrue(s->largestVariance("abc"), 0);
  assertTrue(s->largestVariance("abcde"), 0);
  assertTrue(s->largestVariance("abba"), 1);
  assertTrue(s->largestVariance("abbba"), 2);
  assertTrue(s->largestVariance("ababab"), 1);
}
