#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int i,n,j,m,k,e;
bool answer = false;

int main() {
  cin >> n >> m;
  bool bad = false;
  for (i = 0; i < m; i++) {
    set<int> a;
    cin >> k;
    bad = true;
    for (j = 0; j < k; j++) {
      cin >> e;
      if (bad) {
        if (a.find(-e) != a.end()) {
          bad = false;
        } else {
          a.insert(e);
        }
      }
    }
    if (bad) {
      answer = true;
    }
  }
  if (answer) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
