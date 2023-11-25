#include <iostream>
#include <algorithm>

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

void assertEq(double res, double expected, double threshold) {
  if (abs(expected - res) >= threshold) {
    cout << "case: " << caseIdx <<  " expected: " << expected << " but was: " << res << "\n";
  } else {
    cout << "case: " << caseIdx <<  " successful\n";
  }
  caseIdx++;
}

template<typename T>
void assertEq(std::vector<T> res, std::vector<T> expected) {
  if (res.size() != expected.size()) {
    cout << "case: " << caseIdx <<  " expected size() to be: " << expected.size() << " but was: " << res.size() << "\n";
  } else {
    for (int idx = 0; idx < res.size(); idx++) {
      if (res[idx] != expected[idx]) {
        cout << "case: " << caseIdx <<  " expected [" << idx << "] to be: " << expected[idx] << " but was: " << res[idx] << "\n";
      }
    }
  }
  caseIdx++;
}
