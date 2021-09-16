#include <vector>
using namespace std;

// Sort based on the finish value
static bool compare(vector<int> &A, vector<int> &B) { return A[1] < B[1]; }

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// Returns the max number of intervals that can be scheduled without conflicts
int intervalScheduling(vector<vector<int>> &intervals) {
  int n = intervals.size();
  if (n < 2) {
    return n;
  }
  sort(intervals.begin(), intervals.end(), compare);
  int maxIntervals = 1;
  int furthestFinishTime = intervals[0][1];
  for (int i = 1; i < n; i++) {
    if (intervals[i][0] > furthestFinishTime) {
      maxIntervals++;
      furthestFinishTime = intervals[i][1];
    }
  }
  return maxIntervals;
}