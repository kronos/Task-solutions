#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int n, m;
string s, t;
int cnt[1000];
int main() {
  cin >> n >> m;
  cin >> s >> t;
  for (int i = 0; i <= m-n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[j] != t[i + j]) {
        cnt[i]++;
      }
    }
  }
  int imax = 0;
  for (int i = 1; i <= m-n; i++) {
    if (cnt[i] < cnt[imax]) {
      imax = i;
    }
  }
  cout << cnt[imax] << endl;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i+imax]) {
      cout << i + 1 << " ";
    }
  }
  return 0;
}
