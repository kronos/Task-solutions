#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <cstring>

const int mod = 1000000007;

using namespace std;

int P[100001];
int d[100001];
unsigned long long int VDOWN[100001][22];
unsigned long long int VUP[100001][22];
unsigned long long int V[100001][22];
vector<int> children[100001];
int k;

int calc(int v) {
  unsigned long long int t = d[v];
  unsigned long long int ans = V[v][0];
  VDOWN[v][0] = VUP[v][0] = 0;

  for (int i = 1; i <= k; i++) {
    ans = (ans + V[v][i] * t) % mod;
    t = (t * d[v]) % mod;
    VDOWN[v][i] = VUP[v][i] = 0;
  }

  return ans;
}

void handle(int v, unsigned long long int* curry, int h, unsigned long long int* t) {
  int len = cch[v].size();

  d[v] = h;

  if (len > 0) {
    unsigned long long int r[22];
    unsigned long long int rr[22];

    for (int i = 0; i <= k; i++) {
      r[i] = (VDOWN[v][i] + curry[i]) % mod;
      t[i] = 0;
    }

    for (int i = 0; i < len; i++) {
      handle(cch[v][i], r, h+1, rr);
      for (int j = 0; j <= k; j++) {
        t[j] = t[j] + rr[j];
      }
    }

    for (int i = 0; i <= k; i++) {
      t[i] = (t[i] + VUP[v][i]) % mod;
      V[v][i] = t[i] + r[i];
    }
  } else {
    for (int i = 0; i <= k; i++) {
      t[i] = VUP[v][i];
      V[v][i] = (VUP[v][i] + VDOWN[v][i] + curry[i]) % mod;
    }
  }
}


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int t, type, v, q, qj, root, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);

    for (int j = 1; j <= n; j++) {
      scanf("%d", &P[j]);

      if (P[j] == 0) {
        root = j;
      } else {
        cch[P[j]].push_back(j);
      }
    }

    scanf("%d", &q);
    while (q--) {
      scanf("%d%d", &type, &v);
      if (type == 1) {
        for (int j = 0; j <= k; j++) {
          scanf("%d", &qj);
          VDOWN[v][j] += qj;
        }
      } else {
        for (int j = 0; j <= k; j++) {
          scanf("%d", &qj);
          VUP[v][j] += qj;
        }
      }
    }

    unsigned long long int r[22] = {0};
    unsigned long long int t[22] = {0};
    handle(root, r, 1, t);

    for (int j = 1; j <= n; j++) {
      printf("%d ", calc(j));
    }
    printf("\n");
    for (int j = 1; j <= n; j++) {
      cch[j].clear();
    }
  }

  return 0;
}
