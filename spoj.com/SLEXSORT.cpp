#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int d[27], N, j, p;
vector<string> t;
string s,z;

int main() {
  cin >> N;
  while(N--) {
    t.clear();
    cin >> z;
    for(j = 0; j < z.length(); j++) {
      d[z[j]-'a'] = j+'a';
    }
    cin >> j;
    while(j--) {
      cin >> s;
      for(p = 0; p < s.length(); p++) {
        s[p] = d[s[p]-'a'];
      }
      t.push_back(s);
    }

    sort(t.begin(), t.end());
    for(j = 0; j < t.size();) {
      for(p = 0; p < t[j].length(); p++) {
        t[j][p]=z[t[j][p]-'a'];
      }
      cout << t[j++] << endl;
    }
    cout << endl;
  }
}
