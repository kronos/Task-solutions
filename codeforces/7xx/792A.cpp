#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int n;
map<int,int> r;
int a[200000];

int main() {
  int i;
  cin >> n;

  for (i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);

  for (i = 1; i < n; i++) {
    r[a[i] - a[i-1]]++;
  }

  cout << r.begin()->first << " " << r.begin()->second << endl;

  return 0;
}
