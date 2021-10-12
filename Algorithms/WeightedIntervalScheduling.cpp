#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int weightedIntervalScheduling(vector<int> &startTime, vector<int> &endTime,
                               vector<int> &weight) {
  int n = startTime.size();
  vector<pair<pair<int, int>, int>> intervals(n);
  for (int i = 0; i < n; i++) {
    intervals[i] = {{startTime[i], endTime[i]}, weight[i]};
  }
  sort(intervals.begin(), intervals.end());
  for (int i = 0; i < n; i++) {
    startTime[i] = intervals[i].first.first;
  }
  int nextValidIndex;
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