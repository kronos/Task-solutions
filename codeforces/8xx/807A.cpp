#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n;
unsigned long long ans;
int a[1000];
int x[1000];
int b[1000];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  bool rated = false;
  bool unclear = true;
  for (int i = 0; (i < n) && !rated; i++) {
    cin >> a[i] >> b[i];
    rated |= a[i] != b[i];
    x[n-i-1] = a[i];
  }

  if (!rated) {
    sort(a, a+n);
    for (int i = 0; (i < n) && unclear; i++) {
      unclear = a[i] == x[i];
    }
  }

  if (rated) {
    cout << "rated\n";
  } else if (unclear) {
    cout << "maybe\n";
  } else {
    cout << "unrated\n";
  }
  return 0;
}
