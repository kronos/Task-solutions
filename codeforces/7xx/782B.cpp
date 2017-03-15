#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

struct _friend {
  double x;
  double v;
};

bool comparator(const _friend& left, const _friend& right)
{
  return left.x < right.x;
}

int i,j,k,n;

bool check(double time, vector<_friend> arr) {
  double l = arr[0].x - time*arr[0].v;
  double r = arr[0].x + time*arr[0].v;
  double cl, cr;
  for (i = n-1; (i > 0) && (l<=r); i--) {
    cl = arr[i].x - time*arr[i].v;
    cr = arr[i].x + time*arr[i].v;
    if (cl > l) {
      l = cl;
    }
    if (cr < r) {
      r = cr;
    }
  }

  return l <= r;
}

int main() {
  cin >> n;
  vector<_friend> a(n);

  for (i = 0; i < n; i++) {
    cin >> a[i].x;
  }

  for (i = 0; i < n; i++) {
    cin >> a[i].v;
  }
  sort(a.begin(), a.end(), comparator);
  double l = 0.0;
  double r = 1e9;
  double mid;

  while (r-l >= 1e-6) {
    mid = l + (r-l)/2.0;
    if (check(mid, a)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.7f\n", mid);
  return 0;
}
