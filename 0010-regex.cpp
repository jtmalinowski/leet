// g++ -std=c++11 0010-regex.cpp -o app -fsanitize=address -static-libsan -g && ./app
// leet uses c++11

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
  bool _match(string &s, int idxS, string &p, int idxP)
  {
    if (idxS >= s.size() && idxP >= p.size())
    {
      // both are consumed
      return true;
    }

    if (idxP >= p.size())
    {
      // consumed pattern but not the text
      return false;
    }

    if ((idxP < p.size() - 1) && (p[idxP + 1] == '*'))
    {
      if (idxS >= s.size() && idxP == p.size() - 2)
      {
        // text is consumed and we're on star-matching of last char
        return true;
      }

      if (idxS >= s.size())
      {
        // text is consumed but pattern is not
        return _match(s, idxS, p, idxP + 2);
      }

      bool matchSkipStar = _match(s, idxS, p, idxP + 2);
      if (p[idxP] == '.')
      {
        // matches no matter what, so move to next
        return matchSkipStar || _match(s, idxS + 1, p, idxP);
      }

      if (p[idxP] == s[idxS])
      {
        // matched the char, proceed both ways
        return matchSkipStar || _match(s, idxS + 1, p, idxP);
      }

      return matchSkipStar;
    }

    if (idxS >= s.size())
    {
      // text are consumed
      return false;
    }

    if (p[idxP] == s[idxS] || p[idxP] == '.')
    {
      // matched the char, proceed
      return _match(s, idxS + 1, p, idxP + 1);
    }

    return false;
  }

  bool isMatch(string s, string p)
  {
    return _match(s, 0, p, 0);
  }
};

#include "./utils/assert.cpp"

int main()
{
  assertTrue((new Solution())->isMatch("a", "a"), true);
  assertTrue((new Solution())->isMatch("ab", "ab"), true);
  assertTrue((new Solution())->isMatch("ab", ".*"), true);
  assertTrue((new Solution())->isMatch("ab", "a"), false);
  assertTrue((new Solution())->isMatch("a", "a*a"), true);
  assertTrue((new Solution())->isMatch("aa", "a*a"), true);
  assertTrue((new Solution())->isMatch("aaa", "a*a"), true);
  assertTrue((new Solution())->isMatch("aab", "c*a*b"), true);
  assertTrue((new Solution())->isMatch("ab", ".*c"), false);
  assertTrue((new Solution())->isMatch("a", ".*..a*"), false);
  assertTrue((new Solution())->isMatch("a", ".*b*"), true);
}
