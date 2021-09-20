#include <stack>
#include <vector>
using namespace std;

// Time Complexity: O(v + e) -> v and e are number of nodes and edges
// Space Complexity: O(v + e)
vector<int> dfs(vector<vector<int>> &graph) {
  stack<int> s;
  int curr;
  int index = 0;
  int n = graph.size();

  // Store the DFS Ordering
  vector<int> dfsTraversal(n, 0);

  // Store if the node has been already traversed or not
  vector<bool> visited(n, false);

  // Run DFS for all the connected components
  // The levels in each connected component will start from 0
  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      continue;
    }
    s.push(i);
    visited[i] = true;

    while (!s.empty()) {
      curr = s.top();
      s.pop();
      dfsTraversal[index++] = curr;
      for (int j = 0; j < graph[curr].size(); j++) {
        if (!visited[graph[curr][j]]) {
          s.push(graph[curr][j]);
          visited[graph[curr][j]] = true;
        }
      }
    }
  }
  return dfsTraversal;
}