#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n, answer;
string s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "Icosahedron") {
      answer += 20;
    } else if (s == "Cube") {
      answer += 6;
    } else if (s == "Tetrahedron") {
      answer += 4;
    } else if (s == "Dodecahedron") {
      answer += 12;
    } else if (s == "Octahedron") {
      answer += 8;
    }
  }
  cout << answer;
  return 0;
}
