#include <queue>
#include <vector>
using namespace std;

// Sort based on the start value
static bool compare(vector<int> &A, vector<int> &B) { return A[0] < B[0]; }

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// Returns the min number of rooms for all intervals to be scheduled
int intervalPartitioning(vector<vector<int>> &intervals) {
  int n = intervals.size();
  if (n < 2) {
    return n;
  }
  sort(intervals.begin(), intervals.end(), compare);
  priority_queue<int, vector<int>, greater<int>> pq;
  int minRooms = 1;
  pq.push(intervals[0][1]);
  for (int i = 1; i < n; i++) {
    if (intervals[i][0] <= pq.top()) {
      minRooms++;
    } else {
      pq.pop();
    }
    pq.push(intervals[i][1]);
  }
  return minRooms;
}