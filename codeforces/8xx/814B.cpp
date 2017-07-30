#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int n, m;
int a[1000];
int b[1000];
int c[1000];
bool used[1001];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  bool first = false;
  int first_idx;
  int second_idx = -1;

  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      c[i] = a[i];
      used[c[i]] = true;
    } else {
      if (first) {
        second_idx = i;
      } else {
        first = true;
        first_idx = i;
      }
    }
  }

  if (second_idx > 0) {
    vector<int> nums;
    if (!used[a[first_idx]]) {
      nums.push_back(a[first_idx]);
      used[a[first_idx]] = true;
    }

    if (!used[b[first_idx]]) {
      nums.push_back(b[first_idx]);
      used[b[first_idx]] = true;
    }

    if (!used[a[second_idx]]) {
      nums.push_back(a[second_idx]);
      used[a[second_idx]] = true;
    }

    if (!used[b[second_idx]]) {
      nums.push_back(b[second_idx]);
    }

    if (((a[first_idx] == nums[0] && a[second_idx] != nums[1]) ||
         (a[first_idx] != nums[0] && a[second_idx] == nums[1])) &&
        ((b[first_idx] == nums[0] && b[second_idx] != nums[1]) ||
         (b[first_idx] != nums[0] && b[second_idx] == nums[1]))) {
      c[first_idx] = nums[0];
      c[second_idx] = nums[1];
    } else {
      c[first_idx] = nums[1];
      c[second_idx] = nums[0];
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        c[first_idx] = i;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << c[i] << " ";
  }

  return 0;
}
