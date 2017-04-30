#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
int n;
int a[50];
int P[50];
vector<int> ch[50];

unsigned long long calc(int v, unsigned long long cnt) {
  unsigned long long ans = a[v]*cnt;
  for (int i = 0; i < ch[v].size(); i++) {
    ans += calc(ch[v][i], cnt*2);
  }
  return ans;
}

int main() {
  int n, m, k, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> m;
    for (int j = 0; j < m; j++) {
      cin >> k;
      P[k-1] = i;
      ch[i].push_back(k-1);
    }
  }
  cout << sum << " " << calc(0, 1) << endl;
  return 0;
}
