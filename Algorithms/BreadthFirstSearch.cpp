#include <queue>
#include <vector>
using namespace std;

// Time Complexity: O(v + e) -> v and e are number of nodes and edges
// Space Complexity: O(v + e)
vector<int> bfs(vector<vector<int>> &graph) {
  queue<int> q;
  int curr;
  int index = 0;
  int n = graph.size();

  // Store the BFS Ordering
  vector<int> bfsTraversal(n, 0);

  // Store if the node has been already traversed or not
  vector<bool> visited(n, false);

  // Run BFS for all the connected components
  // The levels in each connected component will start from 0
  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      continue;
    }
    q.push(i);
    visited[i] = true;

    while (!q.empty()) {
      curr = q.front();
      q.pop();
      bfsTraversal[index++] = curr;
      for (int j = 0; j < graph[curr].size(); j++) {
        if (!visited[graph[curr][j]]) {
          q.push(graph[curr][j]);
          visited[graph[curr][j]] = true;
        }
      }
    }
  }
  return bfsTraversal;
}