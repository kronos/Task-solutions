#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
long long n,k;
unsigned long long ans;
int a[200001]; // 10^5
long long ssum[200001];
long long t[200001];
int fenwick[200001];
size_t uniq;

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) {
    t[i] = t[i<<1] + t[i<<1|1];
  }
}

size_t uniquize() {
  int pos = 1;
  for (int i = 1; i < n; i++) {
    if (t[i] != t[i-1]) {
      t[pos++] =t[i];
    }
  }

  return pos;
}

int sum_fenwick(long long id) {
  int sum = 0;

  for (id++; id > 0; id -= id & -id) {
    sum += fenwick[id];
  }

  return sum;
}

void add_fenwick(long long id, int value) {
  if (value == 0 || id < 0) {
    return;
  }

  for(id++; id < 200001; id += id & -id) {
    fenwick[id] += value;
  }
}


int binary_search(long long v) {
  int l = -1;
  int r = uniq;
  int mid;
  while (r-l > 1) {
    mid = (l+r) >> 1;
    if (t[mid] < v) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return r;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    t[i-1] = ssum[i] = ssum[i-1] + a[i] - k;
  }
  sort(t, t+n);
  uniq = uniquize();
  long long id;

  for (int i = 0; i <= n; i++) {
    id = binary_search(ssum[i]);
    ans += sum_fenwick(id);
    add_fenwick(id, 1);
  }
  cout << ans << endl;

  return 0;
}
