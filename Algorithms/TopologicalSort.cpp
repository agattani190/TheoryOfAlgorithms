#include <unordered_map>
#include <vector>
using namespace std;

// Time Complexity: O(n + m) -> n and m are number of nodes and edges
// Space Complexity: O(n + m)
// Returns the topological ordering of the nodes if it exists
// Return an empty array otherwise
vector<int> topologicalSort(vector<vector<int>> graph) {
  int n = graph.size();
  vector<int> ordering(n, -1);
  vector<int> inDegree(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < graph[i].size(); j++) {
      inDegree[graph[i][j]]++;
    }
  }
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (inDegree[i] == 0) {
      ordering[index++] = i;
    }
  }
  if (index == n) {
    return ordering;
  }
  for (int i = 0; i < n; i++) {
    if (ordering[i] == -1) {
      return {};
    }
    for (int j = 0; j < graph[ordering[i]].size(); j++) {
      inDegree[graph[ordering[i]][j]]--;
      if (inDegree[graph[ordering[i]][j]] == 0) {
        ordering[index++] = graph[ordering[i]][j];
      }
    }
  }
  return ordering;
}
