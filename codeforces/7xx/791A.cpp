#include <iostream>

using namespace std;

int main() {
  int answer, a, b;
  cin >> a >> b;
  for (answer = 0; a <= b; ++answer) {
    a*=3;
    b*=2;
  }
  cout << answer;
  return 0;
}
