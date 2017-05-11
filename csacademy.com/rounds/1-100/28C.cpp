#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n;
unsigned long long ans;
int a[100000];
int b[100000];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n,k,t;
  cin >> n >> k;
  if (n == 1) {
    cout << 1;
  } else if (n == 2) {
    if (k & 1) {
      cout << "1 2";
    } else {
      cout << "2 1";
    }
  } else {
    if (n & 1) {
      k = k % 2;
    } else {
      k = k % 4;
    }
    t = n/2;
    for (int i = 0; i < n; i++) {
      a[i] = i;
    }

    for (int j = 0; j < k; j++) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if ((i & 1) == 0) {
          b[cnt++] = a[i];
        }
      }

      for (int i = 0; i < n; i++) {
        if (i & 1) {
          b[cnt++] = a[i];
        }
      }

      cnt = n - 1;
      for (int i = 0; i < n/2; i++) {
        a[cnt--] = b[i];
        a[cnt--] = b[n-i-1];
      }
    }
    if (n & 1) {
      a[0] = b[n/2];
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] + 1 << " ";
    }

  }

  return 0;
}
