#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int> array1, vector<int> array2);

// Time Complexity: O(nlogn)
// Space Complexity: O(nlogn)
vector<int> mergeSort(vector<int> array) {
  int n = array.size();
  if (n < 2) {
    return array;
  }
  int mid = n / 2;
  vector<int> array1 =
      mergeSort(vector<int>(array.begin(), array.begin() + mid));
  vector<int> array2 = mergeSort(vector<int>(array.begin() + mid, array.end()));
  return mergeSortedArrays(array1, array2);
}

vector<int> mergeSortedArrays(vector<int> array1, vector<int> array2) {
  int n1 = array1.size();
  int n2 = array2.size();
  vector<int> mergedArray(n1 + n2);
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < n1 && j < n2) {
    if (array1[i] <= array2[j]) {
      mergedArray[k++] = array1[i++];
    } else {
      mergedArray[k++] = array2[j++];
    }
  }
  while (i < n1) {
    mergedArray[k++] = array1[i++];
  }
  while (j < n2) {
    mergedArray[k++] = array2[j++];
  }
  return mergedArray;
}