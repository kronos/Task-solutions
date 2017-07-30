#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n, q;
unsigned long long ans;
int stack[300000];
int top;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  string cmd;
  cin >> n;
  int current = 1;
  int last_sorted = 0;
  int size = 0;
  int ordered_top = -1;
  for (int i = 0; i < n*2; i++) {
    cin >> cmd;
    if (cmd[0] == 'a') {
      cin >> stack[top];
      top++;
    } else {
      if (stack[top-1] == current || ordered_top == top-1) {
        top--;
        if (ordered_top >= top) {
          ordered_top = top-1;
        }
      } else {
        top--;
        ans++;
        ordered_top = top-1;
      }
      current++;
    }
  }
  cout << ans << "\n";
  return 0;
}
