#include <queue>
#include <vector>
using namespace std;

// Time Complexity: O(v + e) -> v and e are number of nodes and edges
// Space Complexity: O(v)
bool isBipartite(vector<vector<int>> &graph) {
  queue<int> q;
  int size;
  int count;
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
    count = 0;
    q.push(i);
    while (!q.empty()) {
      size = q.size();
      while (size--) {
        curr = q.front();
        q.pop();
        if (!visited[curr]) {
          visited[curr] = true;
          level[curr] = count;
          for (int i = 0; i < graph[curr].size(); i++) {
            q.push(graph[curr][i]);
          }
        }
      }
      count++;
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