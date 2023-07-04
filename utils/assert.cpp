#include <iostream>

using namespace std;

int caseIdx = 0;

void assertTrue(int res, int expected) {
  if (res != expected) {
    cout << "case: " << caseIdx <<  " expected: " << expected << " but was: " << res << "\n";
  } else {
    cout << "case: " << caseIdx <<  " successful\n";
  }
  caseIdx++;
}
