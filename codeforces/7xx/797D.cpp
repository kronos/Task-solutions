#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MMIN = -1;
const int MMAX = 1e9 + 1;

int K[100001];
int L[100001];
int R[100001];
int P[100001];
set<int> visited;
map<int, int> cnt;

int compute(int v, int low, int high) {
  if (v == -1) {
    return 0;
  }

  if (K[v] >= low && K[v] <= high) {
    if (visited.find(K[v]) == visited.end()) {
      visited.insert(K[v]);
      return cnt[K[v]] + compute(L[v], min(low, K[v]), K[v]) + compute(R[v], K[v], high);
    } else {
      return compute(L[v], min(low, K[v]), K[v]) + compute(R[v], K[v], high);
    }
  } else {
    if (K[v] < low) {
      return compute(R[v], low, high);
    } else if (K[v] > high) {
      return compute(L[v], low, high);
    } else {
      return 0;
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  int root = 1;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> K[i] >> L[i] >> R[i];
    cnt[K[i]]++;

    if (L[i] > -1) {
      P[L[i]] = i;
    }

    if (R[i] > -1) {
      P[R[i]] = i;
    }
  }

  while (P[root] > 0) {
    root = P[root];
  }

  cout << n - compute(root, MMIN, MMAX);
  return 0;
}
