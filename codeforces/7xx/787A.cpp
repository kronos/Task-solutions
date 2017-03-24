#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int a,b,c,d;
bool found;
int answer = -1;

int main() {
  cin >> a >> b;
  cin >> c >> d;
  for (int i = 0; (i <= 100) && (answer == -1); i++) {
    for (int j = 0; (j <= 100) && (answer == -1); j++) {
      if (b+a*i == d+c*j) {
        answer = b+a*i;
      }
    }
  }
  cout << answer << endl;
  return 0;
}
