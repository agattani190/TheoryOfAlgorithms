#include <vector>
using namespace std;

// Time Complexity: O(nlogn) -> n and m are number of nodes and edges
// Space Complexity: O(1)
// Returns the min number of coins to make the sum n
int cashierAlgorithm(vector<int> &coins, int n) {
  sort(coins.begin(), coins.end());
  int minCoins = 0;
  for (int i = coins.size() - 1; i >= 0; i--) {
    if (coins[i] <= n) {
      minCoins += (n / coins[i]);
      n %= coins[i];
    }
  }
  return minCoins;
}