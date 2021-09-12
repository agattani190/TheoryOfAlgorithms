#include <vector>
using namespace std;
bool DoesSPrefersH1OverH(vector<vector<int>> studentPreferences, int s, int h,
                         int h1);

// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
vector<int> stableMatching(vector<vector<int>> hospitalPreferences,
                           vector<vector<int>> studentPreferences) {
  int N = hospitalPreferences.size();
  int freeCount = N;

  // Stores the index of the hospital a student is matched with
  vector<int> matchedHospital(N, -1);

  // Stores if the hospital is free or not
  vector<int> isHospitalFree(N, true);

  // While some hospital is free
  while (freeCount > 0) {
    int h;

    // Get the first free hospital
    for (h = 0; h < N; h++) {
      if (isHospitalFree[h]) {
        break;
      }
    }

    for (int i = 0; i < N; i++) {
      int s = hospitalPreferences[h][i];
      if (matchedHospital[s] == -1) {
        matchedHospital[s] = h;
        isHospitalFree[h] = false;
        freeCount--;
        break;
      } else {
        int h1 = matchedHospital[s];
        // If s prefers h over h1, assign s to h1
        if (DoesSPrefersH1OverH(studentPreferences, s, h, h1) == false) {
          matchedHospital[s] = h;
          isHospitalFree[h] = false;
          isHospitalFree[h1] = true;
        }
      }
    }
  }
  return matchedHospital;
}

// Returns true if student s prefers hospital h1 over h
bool DoesSPrefersH1OverH(vector<vector<int>> studentPreferences, int s, int h,
                         int h1) {
  int N = studentPreferences.size();

  // Return true if h1 comes before h in the preference list of s.
  for (int i = 0; i < N; i++) {
    if (studentPreferences[s][i] == h1)
      return true;
    if (studentPreferences[s][i] == h)
      return false;
  }

  return true;
}