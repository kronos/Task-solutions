#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

unsigned long long c, v0, v1, a, l;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> c >> v0 >> v1 >> a >> l;
  unsigned long long ans = 0, days = 0, speed = 0, read = 0;

  while (true) {
    days++;
    speed = min(v0 + a*(days-1), v1);
    read += speed;
    if (read >= c) {
      break;
    }
    read -= l;
  }
  cout << days;
  return 0;
}
