#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int weightedIntervalScheduling(vector<int> &startTime, vector<int> &endTime,
                               vector<int> &weight) {
  int n = startTime.size();

  // Store all the info in a single array
  vector<pair<pair<int, int>, int>> intervals(n);
  for (int i = 0; i < n; i++) {
    intervals[i] = {{startTime[i], endTime[i]}, weight[i]};
  }

  // Sort intervals based on start time
  sort(intervals.begin(), intervals.end());

  // Store the start time in a separate array to easily apply binary search to
  // find the next valid interval compatible with the one chosen
  for (int i = 0; i < n; i++) {
    startTime[i] = intervals[i].first.first;
  }

  int nextValidIndex;

  // Store the previous results in an array
  // dp[i] stores the result for the problem with intervals from i to n
  vector<int> dp(n, 0);
  dp[n - 1] = intervals[n - 1].second;
  for (int i = n - 2; i >= 0; i--) {
    dp[i] = max(intervals[i].second, dp[i + 1]);
    nextValidIndex = lower_bound(startTime.begin() + i, startTime.end(),
                                 intervals[i].first.second) -
                     startTime.begin();
    if (nextValidIndex < n) {
      dp[i] = max(dp[i], intervals[i].second + dp[nextValidIndex]);
    }
  }
  return dp[0];
}