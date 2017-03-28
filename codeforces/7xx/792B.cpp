#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

int k, n;
list<int> q;
list<int>::iterator it;
list<int>::iterator it2;
int a[100];

int main() {
  int i, j = 0;
  cin >> n >> k;

  for (i = 0; i < n; i++) {
    q.push_back(i + 1);
  }

  for (i = 0; i < k; i++) {
    cin >> a[i];
  }

  it = q.begin();

  for (i = 0; i < k; i++) {
    int c = a[i] % n;
    it2 = it;

    while (c--) {
      it2 = next(it2);

      if (it2 == q.end()) {
        it2 = q.begin();
      }
    }

    cout << *it2 << " ";
    it = next(it2);

    if (it == q.end()) {
      it = q.begin();
    }

    q.erase(it2);
    n--;
  }

  return 0;
}
