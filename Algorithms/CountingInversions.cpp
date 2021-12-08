#include <vector>
using namespace std;

int merge(vector<int> &array, int start, int mid, int end);
int countInversionsHelper(vector<int> &array, int start, int end);

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int countInversions(vector<int> array) {
  return countInversionsHelper(array, 0, array.size() - 1);
}

int merge(vector<int> &array, int start, int mid, int end) {
  int i = start;
  int j = mid + 1;
  int k = 0;
  int count = 0;
  vector<int> arr(end - start + 1);
  while (i <= mid && j <= end) {
    if (array[i] <= array[j]) {
      arr[k++] = array[i++];
    } else {
      count += (mid - i + 1);
      arr[k++] = array[j++];
    }
  }
  while (i <= mid) {
    arr[k++] = array[i++];
  }
  while (j <= end) {
    arr[k++] = array[j++];
  }
  i = start;
  j = 0;
  while (j < end - start + 1) {
    array[i++] = arr[j++];
  }
  return count;
}

int countInversionsHelper(vector<int> &array, int start, int end) {
  if (end - start < 1) {
    return 0;
  }
  int mid = start + (end - start) / 2;
  int left = countInversionsHelper(array, start, mid);
  int right = countInversionsHelper(array, mid + 1, end);
  int combine = merge(array, start, mid, end);
  return left + right + combine;
}
