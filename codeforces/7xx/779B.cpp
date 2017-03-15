#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int i,j,k,n, answer;
string s;
int main() {
  cin >> s;
  cin >> k;
  answer = 0;
  if (s == "0") {
    answer = 0;
  } else if (s.length() < k) {
    answer = s.length() - 1;
  } else {
    for (i = s.length() - 1 ; (i>=0) && (k > 0); i--) {
      if (s[i] != '0') {
        answer++;
      } else {
        k--;
      }
    }

    if (k > 0) {
      answer = s.length() - 1;
    }
  }
  cout << answer;
  return 0;
}
