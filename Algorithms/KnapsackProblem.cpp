#include <vector>
using namespace std;

// Time Complexity: O(n*capacity) -> n is the num of nodes in the linked list
// Space Complexity: O(n*capacity)
vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
  int n = items.size();
  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
  vector<int> result;

  // Find the maximum value that can be obtained
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= capacity; j++) {
      dp[i][j] = dp[i - 1][j];
      if (items[i - 1][1] <= j) {
        dp[i][j] =
            max(dp[i][j], dp[i - 1][j - items[i - 1][1]] + items[i - 1][0]);
      }
    }
  }

  // Backtrack to find the items to be included to get the maximum value
  int i = n;
  int j = capacity;
  while (i > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else {
      result.push_back(i - 1);
      j -= items[i - 1][1];
      i--;
    }
  }

  int sz = result.size();
  for (int i = 0; i < sz / 2; i++) {
    swap(result[i], result[sz - i - 1]);
  }

  return {{dp[n][capacity]}, result};
}