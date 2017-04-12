#include <iostream>

using namespace std;

bool holes[1000001];
int main() {
  int n,m,k,x;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    holes[x] = true;
  }
  int current = 1, y;
  if (!holes[1]) {
    for (int i = 0; i < k; i++) {
      scanf("%d %d", &x, &y);
      if (x == current) {
          current = y;
          if (holes[current]) {
              break;
          }
      } else if (y == current) {
          current = x;
          if (holes[current]) {
              break;
          }
      }
    }
  }
  cout << current;
  return 0;
}
