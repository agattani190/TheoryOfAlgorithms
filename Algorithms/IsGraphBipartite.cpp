#include <queue>
#include <vector>
using namespace std;

// Time Complexity: O(v + e) -> v and e are number of nodes and edges
// Space Complexity: O(v + e)
bool isBipartite(vector<vector<int>> &graph) {
  queue<int> q;
  int curr;
  int n = graph.size();

  // Store the level of each node after running the BFS algorithm
  vector<int> level(n, 0);

  // Store if the node has been already traversed or not
  vector<bool> visited(n, false);

  // Run BFS for all the connected components
  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      continue;
    }
    q.push(i);
    while (!q.empty()) {
      curr = q.front();
      q.pop();
      if (!visited[curr]) {
        visited[curr] = true;
        for (int i = 0; i < graph[curr].size(); i++) {
          level[graph[curr][i]] = level[curr] + 1;
          q.push(graph[curr][i]);
        }
      }
    }
  }

  // For every edge in the graph, check if both the nodes belong to the same set
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < graph[i].size(); j++) {
      if ((level[i] + level[graph[i][j]]) % 2 == 0) {
        return false;
      }
    }
  }

  return true;
}