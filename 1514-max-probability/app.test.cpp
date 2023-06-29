// g++ -std=c++11 app.test.cpp -o app

#include <iostream>
#include <vector>

#include "app.cpp"

using namespace std;

void test(double expected, int n, const vector<vector<int> >& edges, const vector<double>& succProb, int start, int end) {
  Solution* s = new Solution();
  double result = s->maxProbability(n, edges, succProb, start, end);
  if (abs(result - expected) > 0.00001) {
    std::cout << "expected: " << expected << " but got: " << result << "\n";
  }
}

int main()
{
  test(0.25, 3, { {0,1}, {1,2}, {0,2} }, {0.5,0.5,0.2}, 0, 2);
  test(0.3, 3, { {0,1}, {1,2}, {0,2} }, {0.5,0.5,0.3}, 0, 2);
  test(0, 3, { {0,1} }, {0.5}, 0, 2);
  test(0.125, 4, { {0,1}, {1,2}, {2,3}, {0,3} }, {0.5,0.5,0.5,0.1}, 0, 3);
}
