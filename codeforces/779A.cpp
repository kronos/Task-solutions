#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int i,j,k,n;
int ma[6];
int mb[6];
bool bad = false;
int answer = 0;

int main() {
  int x;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    ma[x]++;
  }

  for (i = 0; i < n; i++) {
    cin >> x;
    mb[x]++;
  }
  int needa = 0;
  int needb = 0;
  for (i = 1; (i<=5) && (!bad); i++) {
    if (ma[i] != mb[i]) {
      if (abs(ma[i] - mb[i]) % 2 != 0) {
        bad = true;
      } else if (ma[i] > mb[i]) {
        needb += (ma[i] - mb[i]) / 2;
      } else {
        needa += (mb[i] - ma[i]) / 2;
      }
    }
  }

  if (bad || (needa != needb)) {
    cout << -1;
  } else {
    cout << needa;
  }
  return 0;
}
