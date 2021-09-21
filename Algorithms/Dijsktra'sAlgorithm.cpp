#include <queue>
#include <vector>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
  int n = edges.size();

  // Initialize the shortest distance for all nodes to Infinity
  vector<int> shortestDistance(n, INT_MAX);

  // Shortest distance from a node to itself is 0
  shortestDistance[start] = 0;

  priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>,
                 greater<pair<pair<int, int>, int>>>
      pq;

  // Push the edges from the starting node in the priority queue
  for (int i = 0; i < edges[start].size(); i++) {
    pq.push({{edges[start][i][1], edges[start][i][0]}, start});
  }

  int u, v, weight;
  while (!pq.empty()) {
    u = pq.top().second;
    v = pq.top().first.second;
    weight = pq.top().first.first;
    pq.pop();

    // If the shortest path to v decreases when travelled through u, update it
    // Add edges from v to the priority queue
    if (shortestDistance[u] + weight < shortestDistance[v]) {
      shortestDistance[v] = shortestDistance[u] + weight;
      for (int i = 0; i < edges[v].size(); i++) {
        pq.push({{edges[v][i][1], edges[v][i][0]}, v});
      }
    }
  }

  // Update the value of the nodes unreachable from starting vertex to -1
  for (int i = 0; i < n; i++) {
    if (shortestDistance[i] == INT_MAX) {
      shortestDistance[i] = -1;
    }
  }
  return shortestDistance;
}
