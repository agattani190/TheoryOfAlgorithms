#include <vector>
using namespace std;

void dfsHelper(vector<vector<int>> &graph, vector<int> &dfsOrdering,
               vector<bool> &visited, int src);

// Time Complexity: O(v + e) -> v and e are number of nodes and edges
// Space Complexity: O(v + e)
vector<int> dfs(vector<vector<int>> &graph) {
  int curr;
  int n = graph.size();

  // Store the DFS Ordering
  vector<int> dfsTraversal;

  // Store if the node has been already traversed or not
  vector<bool> visited(n, false);

  // Run DFS for all the connected components
  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      continue;
    }
    visited[i] = true;
    dfsHelper(graph, dfsTraversal, visited, curr);
  }
  return dfsTraversal;
}

void dfsHelper(vector<vector<int>> &graph, vector<int> &dfsTraversal,
               vector<bool> &visited, int src) {
  dfsTraversal.push_back(src);
  for (int j = 0; j < graph[src].size(); j++) {
    if (!visited[graph[src][j]]) {
      visited[graph[src][j]] = true;
      dfsHelper(graph, dfsTraversal, visited, graph[src][j]);
    }
  }
}