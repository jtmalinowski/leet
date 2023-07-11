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

void assertEq(string res, string expected) {
  if (res != expected) {
    cout << "case: " << caseIdx <<  " expected: " << expected << " but was: " << res << "\n";
  } else {
    cout << "case: " << caseIdx <<  " successful\n";
  }
  caseIdx++;
}

void assertEq(int res, int expected) {
  if (res != expected) {
    cout << "case: " << caseIdx <<  " expected: " << expected << " but was: " << res << "\n";
  } else {
    cout << "case: " << caseIdx <<  " successful\n";
  }
  caseIdx++;
}

void assertEq(bool res, bool expected) {
  if (res != expected) {
    cout << "case: " << caseIdx <<  " expected: " << expected << " but was: " << res << "\n";
  } else {
    cout << "case: " << caseIdx <<  " successful\n";
  }
  caseIdx++;
}
