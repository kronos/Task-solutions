#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n,t;
int a[100000]; // 10^5

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> t;
  int left = t;
  int yan = 0, nathan = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (left >= a[i]) {
      left -= a[i];
      yan++;
    } else {
      left = 0;
    }
  }
  left = t;
  for (int i = n-1; i >= 0; i--) {
    if (left >= a[i]) {
      left -= a[i];
      nathan++;
    } else {
      break;
    }
  }

  if (yan == nathan) {
    cout << "Empate\n";
  } else if (yan > nathan) {
    cout << "Yan\n";
  } else {
    cout << "Nathan\n";
  }
  return 0;
}
