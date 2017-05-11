#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

struct ts {
  int p;
  short int a,b;
};
int n, m;
ts tss[200001];
bool bought[200001];
int x[3][400001];
int cnt[3];
int r_cnt[3];

bool comparator(const ts& left, const ts& right) {
  return left.p < right.p;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> tss[i].p;
  }

  for (int i = 0; i < n; i++) {
    cin >> tss[i].a;
  }

  for (int i = 0; i < n; i++) {
    cin >> tss[i].b;
  }

  sort(tss, tss + n, comparator);
  int idx, t;

  for (int i = 0; i < n; i++) {
    idx = tss[i].a - 1;
    x[idx][cnt[idx]++] = i;

    if (idx != tss[i].b - 1) {
      idx = tss[i].b - 1;
      x[idx][cnt[idx]++] = i;
    }
  }

  cin >> m;
  bool good = true;
  int q;
  for (int i = 0; i < m; i++) {
    cin >> t;
    t--;

    good = false;
    q = r_cnt[t];
    while (q < cnt[t]) {
      idx = x[t][q];

      if (bought[idx]) {
        q++;
      } else {
        good = true;
        bought[idx] = true;
        cout << tss[idx].p << ' ';
        q++;
        break;
      }
    }

    r_cnt[t] = q;

    if (!good) {
      cout << "-1  ";
    }
  }
  return 0;
}
