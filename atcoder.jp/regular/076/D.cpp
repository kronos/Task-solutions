#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;
int n;
unsigned long long ans;
struct town {
  int i, x, y;//, price;
};

town towns_x[100000];
town towns_y[100000];
int p[100000];
int r[100000];

bool x_sort(const town &l, const town &r) {
  return l.x < r.x;
}

bool y_sort(const town &l, const town &r) {
  return l.y < r.y;
}

struct D {
  int d, i, j;

  bool operator() (const D& left, const D& right) const {
    return left.d >= right.d;
  }
};

int find(int x) {
    if (x != p[x]) {
        p[x] = find(p[x]);
    }

    return p[x];
}

void merge(int x, int y) {
    int p_x = find(x);
    int p_y = find(y);
    if (p_y != p_x) {
        if (r[p_y] > r[p_x]) {
            p[p_x] = p_y;
        } else {
            p[p_y] = p_x;
            if (r[p_y] == r[p_x]) {
                r[p_x]++;
            }
        }
    }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> towns_x[i].x >> towns_x[i].y;
    towns_x[i].i = i;
    towns_y[i] = towns_x[i];
    p[i] = i;
  }

  sort(towns_x, towns_x + n, x_sort);
  sort(towns_y, towns_y + n, y_sort);

  priority_queue<D, std::vector<D>, D> pq;

  for (int i = 1; i < n; i++) {
    D d;
    d.d = towns_x[i].x - towns_x[i-1].x;
    d.i = towns_x[i].i;
    d.j = towns_x[i-1].i;
    pq.push(d);

    d.d = towns_y[i].y - towns_y[i-1].y;
    d.i = towns_y[i].i;
    d.j = towns_y[i-1].i;
    pq.push(d);
  }

  while (!pq.empty()) {
    D d = pq.top();
    pq.pop();

    if (find(d.i) != find(d.j)) {
      merge(d.i, d.j);
      ans += d.d;
    }
  }

  cout << ans << "\n";

  return 0;
}
