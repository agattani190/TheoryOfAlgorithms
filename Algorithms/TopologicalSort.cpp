#include <unordered_map>
#include <vector>
using namespace std;

// Time Complexity: O(n + m) -> n and m are number of nodes and edges
// Space Complexity: O(n + m)
// Returns the topological ordering of the nodes if it exists
// Return an empty array otherwise
vector<int> topologicalSort(vector<vector<int>> graph) {
  int n = graph.size();

  // Stores the topological ordering
  vector<int> ordering(n, -1);

  // Stores the in degree for each node
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
    // If no node with in degree exist, then a topological ordering is not
    // possible.
    if (ordering[i] == -1) {
      return {};
    }

    for (int j = 0; j < graph[ordering[i]].size(); j++) {
      // Remove the edges from the node which is to be deleted
      inDegree[graph[ordering[i]][j]]--;
      if (inDegree[graph[ordering[i]][j]] == 0) {
        ordering[index++] = graph[ordering[i]][j];
        if (index == n) {
          return ordering;
        }
      }
    }
  }
  return ordering;
}
