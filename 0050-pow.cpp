// g++ -std=c++11 0050-pow.cpp -o app -fsanitize=address -static-libsan -g && ./app
// leet uses c++11

#include <map>

using namespace std;

class Solution
{
private:
  double calc(double x, long n)
  {
    if (n == 0)
    {
      return 1;
    }

    if (x == 0)
    {
      return x;
    }

    if (n < 0)
    {
      return 1.0 / calc(x, -n);
    }

    if (n == 1)
    {
      return x;
    }

    if (n == 2)
    {
      return x * x;
    }

    auto half = calc(x, n / 2);
    if (n % 2 == 0)
    {
      return half * half;
    }
    else
    {
      return half * half * x;
    }
  }

public:
  double myPow(double x, int n)
  {
    return calc(x, n);
  }
};

#include "utils/assert.cpp"

int main()
{
  assertEq((new Solution())->myPow(2, 0), 1);
  assertEq((new Solution())->myPow(2, 1), 2);
  assertEq((new Solution())->myPow(2, 2), 4);
  assertEq((new Solution())->myPow(2, 3), 8);
  assertEq((new Solution())->myPow(2, 4), 16);

  assertEq((new Solution())->myPow(2, -1), 0.5, 0.001);
  assertEq((new Solution())->myPow(2, -2), 0.25, 0.001);
  assertEq((new Solution())->myPow(2, -3), 0.125, 0.001);

  assertEq((new Solution())->myPow(1.1, 100), 13780.6, 1);
  assertEq((new Solution())->myPow(1, -2147483648), 1, 1);
}
