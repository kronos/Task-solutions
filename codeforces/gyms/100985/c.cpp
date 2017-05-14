#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int x, y, i, q;

int main() {
  cin >> x >> y;

  if (x > y) {
    cout  << "1 " << x-y << endl;
    x -= x-y;
  } else {
    cout  << "2 " << y-x << endl;
    y -= y-x;
  }

  while (x > 0 || y > 0) {
    cin >> i >> q;

    if (i == 1) {
      x -= q;
    } else {
      y -= q;
    }

    if (x > y) {
      cout  << "1 " << x-y << endl;
      x -= x-y;
    } else {
      cout  << "2 " << y-x << endl;
      y -= y-x;
    }
  }

  return 0;
}
