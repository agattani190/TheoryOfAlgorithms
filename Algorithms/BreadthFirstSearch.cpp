#include <queue>
#include <vector>
using namespace std;

// Time Complexity: O(v + e) -> v and e are number of nodes and edges
// Space Complexity: O(v + e)
vector<int> bfs(vector<vector<int>> &graph) {
  queue<int> q;
  int curr;
  int n = graph.size();

  // Store the level of each node after running the BFS algorithm
  vector<int> level(n, 0);

  // Store if the node has been already traversed or not
  vector<bool> visited(n, false);

  // Run BFS for all the connected components
  // The levels in each connected component will start from 0
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
  return level;
}