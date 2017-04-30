#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n;
long  a[200000];
long  t[200000];

set<int> s;

long long merge(long arr[], long temp[], long left, long mid, long right) {
  long i, j, k;
  long  long inv_count = 0;

  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      if (arr[j]-arr[i] == 1) {
        inv_count++;
      }
          temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  while (i <= mid - 1) {
    temp[k++] = arr[i++];
  }

  while (j <= right) {
    temp[k++] = arr[j++];
  }

  for (i=left; i <= right; i++) {
    arr[i] = temp[i];
  }

  return inv_count;
}

long long mergeSort(long arr[], long temp[], long left, long right) {
  long long inv_count = 0;
  long mid;
  if (right > left) {
    mid = (right + left)/2;
    inv_count  = mergeSort(arr, temp, left, mid);
    inv_count += mergeSort(arr, temp, mid+1, right);
    inv_count += merge(arr, temp, left, mid+1, right);
  }

  return inv_count;
}


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cout << n - mergeSort(a, t, 0, n-1) << endl;
  return 0;
}
