#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
int n;
int a[4];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(a, a+4);
  bool x  = a[3] >= a[0] + a[1] + a[2];
  if (x) {
    cout << "No";
  } else {
    x = ((a[0] + a[1]) == (a[2] + a[3])) ||
        ((a[0] + a[2]) == (a[1] + a[3])) ||
        ((a[0] + a[3]) == (a[1] + a[2]));
    if (x) {
      cout << "Yes";
    } else {
      cout << "No";
    }
  }
  return 0;
}
