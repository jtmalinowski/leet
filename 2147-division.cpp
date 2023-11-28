// g++ -std=c++11 2147-division.cpp -o app -fsanitize=address -static-libsan -g && ./app

#include <set>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
  int numberOfWays(string corridor)
  {
    int lastSegmentEnd = -1;
    int seats = 0;
    int res = 1;
    
    for (int idx = 0; idx < corridor.size(); idx++)
    {
      char c = corridor[idx];
      if (c == 'P') {
        continue;
      }

      if (seats == 0) {
        if (lastSegmentEnd != -1) {
          res = _moduloMul(res, (idx - lastSegmentEnd), 1000000007);
        }

        seats++;
        continue;
      }

      lastSegmentEnd = idx;
      seats = 0;
    }

    if (seats == 1) {
      return 0;
    }

    if (lastSegmentEnd == -1) {
      return 0;
    }
    
    return res;
  }

  int _moduloMul(int a, int b, int modul) {
    if (a == 0 || b == 0) {
      return 0;
    }
    if (a == 1) {
      return b;
    }
    if (b == 1) {
      return a;
    }

    int half = _moduloMul(a, b / 2, modul);
    int evenRes = (half + half) % modul;

    if (b % 2 == 0) {
      return evenRes;
    }

    return (a + evenRes) % modul;
  }
};

#include "utils/assert.cpp"

int main()
{
  assertEq((new Solution())->numberOfWays("SSPPSPS"), 3);
  assertEq((new Solution())->numberOfWays("PPSPSP"), 1);
  assertEq((new Solution())->numberOfWays("S"), 0);
  assertEq((new Solution())->numberOfWays("SSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSS"), 999999937);
  assertEq((new Solution())->numberOfWays("SSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSSPPPPPPPPPSS"), 999999307);
  return 0;
}
