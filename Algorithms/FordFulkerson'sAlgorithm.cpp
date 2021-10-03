#include <queue>
#include <vector>
using namespace std;

bool bfs(vector<vector<int>> &graph, vector<int> &parent);

// Time Complexity: O(ve^2) -> v and e are number of nodes and edges
// Space Complexity: O(v)
int getMaxFlow(vector<vector<int>> &graph) {
  int n = graph.size();

  // Stores the parent of every node
  vector<int> parent(n, -1);

  int maxFlow = 0;
  int flow;
  int u;

  // Check if there is a path available from source to sink
  // First vertex of the graph is source and last vertex of the  graph is sink
  while (bfs(graph, parent)) {
    // Calculate the flow for the path returned by BFS
    flow = INT_MAX;
    for (int v = n - 1; v != 0; v = parent[v]) {
      u = parent[v];
      flow = min(flow, graph[u][v]);
    }

    // Update the value of max flow
    maxFlow += flow;

    // Update capacities of edges & add new edges to create a residual graph
    for (int v = n - 1; v != 0; v = parent[v]) {
      u = parent[v];
      graph[u][v] -= flow;
      graph[v][u] += flow;
    }
  }
  return maxFlow;
}

// Time Complexity: O(v + e) -> v and e are number of nodes and edges
// Space Complexity: O(v)
bool bfs(vector<vector<int>> &graph, vector<int> &parent) {
  int n = graph.size();
  vector<bool> visited(n, false);

  visited[0] = true;
  queue<int> q;
  q.push(0);
  int u;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int v = 0; v < n; v++) {
      if (!visited[v] && graph[u][v] > 0) {
        parent[v] = u;
        if (v == n - 1) {
          return true;
        }
        visited[v] = true;
        q.push(v);
      }
    }
  }
  return false;
}