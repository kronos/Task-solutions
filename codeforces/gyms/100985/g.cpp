#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
string s;
int a,b,la,lb;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  bool paired = true;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A') {
      a++;
    } else {
      b++;
      lb = i;
    }
  }

  paired = a == b;

  if (paired) {
    la = lb;
    while (paired && a > 0) {
      la = min(la, lb-1);
      while (la >= 0 && s[la] != 'A') {
        la--;
      }

      if (la < 0) {
        paired = false;
      } else {
        a--;
        lb--;
        la--;
        while (lb >= 0 && s[lb] != 'B') {
          lb--;
        }
      }
    }
  }

  if (paired) {
    cout << "Sim\n";
  } else {
    cout << "Nao\n";
  }
  return 0;
}
