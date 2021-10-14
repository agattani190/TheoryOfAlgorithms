#include <vector>
using namespace std;

// Returns the minimum number of coins needed to make the change
// Returns -1 if it is not possible
// Time Complexity: O(nm) -> m is size of coins
// Space Complexity: O(n)
int coinChange(vector<int> &coins, int n) {
  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < coins.size(); j++) {
      if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
      }
    }
  }
  if (dp[n] == INT_MAX) {
    return -1;
  }
  return dp[n];
}