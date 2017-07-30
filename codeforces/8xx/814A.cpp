#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int n, k;
int a[100];
int b[100];
vector<int> z;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      z.push_back(i);
    }
  }

  for (int i = 0; i < k; i++) {
    cin >> b[i];
  }

  sort(b, b+k);
  int mmin = b[0];
  int mmax = b[k-1];
  bool can = false;
  bool cons = false;

  for (int i = 1; (i < z.size()) && !cons; i++) {
    cons = z[i] - z[i-1];
  }

  can = cons && mmin != mmax;

  for (int i = 1; (i < n) && !can; i++) {
    can = a[i] != 0 && a[i-1] != 0 && a[i] < a[i-1];
  }

  for (int i = 0; (i < z.size()) && !can; i++) {
    int idx = z[i];
    if (idx > 0) {
      can = (a[idx-1] > mmin) || (idx + 1 < n && a[idx+1] > 0 && a[idx+1] < mmax);
    } else {
      can = a[1] != 0 && mmax > a[1];
    }
  }

  if (can) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
