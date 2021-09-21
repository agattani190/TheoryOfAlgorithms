#include <stack>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &s,
         int src, bool pushToStack) {
  visited[src] = true;
  for (unsigned int i = 0; i < graph[src].size(); i++) {
    if (!visited[graph[src][i]]) {
      dfs(graph, visited, s, graph[src][i], pushToStack);
    }
  }
  if (pushToStack) {
    s.push(src);
  }
}

// Time Complexity: O(v + e) -> v and e are number of nodes and edges
// Space Complexity: O(v + e)
int numberofStronglyConnectedComponents(vector<vector<int>> graph) {
  int n = graph.size();
  vector<vector<int>> transposeGraph(n, vector<int>{});
  vector<bool> visited(n, false);
  stack<int> s;

  // Create a transpose graph
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < graph[i].size(); j++) {
      transposeGraph[graph[i][j]].push_back(i);
    }
  }

  // Traverse the initial graph using the DFS algorithm
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      dfs(graph, visited, s, i, true);
    }
  }

  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }

  int count = 0;

  // Traverse the transpose graph using the DFS algorithm in the order of nodes
  // stored in the stack during the initial traversal
  while (!s.empty()) {
    int top = s.top();
    s.pop();
    if (!visited[top]) {
      count++;
      dfs(transposeGraph, visited, s, top, false);
    }
  }
  return count;
}
