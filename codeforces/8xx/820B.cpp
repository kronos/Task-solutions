#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
double a;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> a;
  double one_angle = 180.0/n;
  double best = 180.0;
  double current = 0;
  int best_x = 3;
  for (int i = 3; i <= n; i++) {
    current += one_angle;
    if (abs(a - current) < best) {
      best = abs(a - current);
      best_x = i;
    }
  }
  cout << "2 1 " << best_x << endl;
  return 0;
}
