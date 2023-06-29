#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Step {
  int node;
  double prob;
};

class Solution {
public:
    double maxProbability(int n, const vector<vector<int> >& edges, const vector<double>& succProb, int start, int end) {
      map<int, double> forwards;
      map<int, map<int, double> > edgesMap;

      for (int i = 0; i < edges.size(); i++) {
        edgesMap.insert(pair<int,map<int,double> >(i, map<int,double>()));
        forwards.insert(pair<int,double>(i, 0));
      }

      for (int i = 0; i < edges.size(); i++) {
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        
        edgesMap[node1][node2] = succProb[i];
        edgesMap[node2][node1] = succProb[i];
      }

      struct CustomLess {
        bool operator()(const Step l, const Step r) const { return l.prob < r.prob; }
      };
      priority_queue<Step, vector<Step>, CustomLess> steps;
      steps.push(Step{start,1});

      while (!steps.empty()) {
        Step step = steps.top();
        steps.pop();

        if (step.prob <= forwards[step.node]) {
          continue;
        }

        forwards[step.node] = step.prob;
        for (auto nxt : edgesMap[step.node]) {
          int nxtNode = nxt.first;
          double edgeProb = nxt.second;
          double res = step.prob * edgeProb;

          if (res > forwards[nxtNode]) {
            steps.push(Step{nxtNode,res});
          }
        }

        if (forwards[end] > 0) { break; }
      }

      return forwards[end];
    }
};
