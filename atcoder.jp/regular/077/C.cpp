#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int a[200000]; //10^5

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = n-1; i >= 0; i-= 2) {
    cout << a[i] << " ";
  }
  int from = n % 2 ? 1 : 0;
  for (int i = from; i < n; i+= 2) {
    cout << a[i] << " ";
  }

  return 0;
}
