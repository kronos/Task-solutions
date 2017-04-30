#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;
map<string, string> sched;
map<string, vector<string> > sp;
int main() {
  int c;
  string s, schedule, caption;
  int n, m, k;
  bool good;
  cin >> c;
  for (int i = 0; i < c; i++) {
    cin >> s >> n;
    for (int j = 0; j < n; j++) {
      cin >> schedule >> caption;
      sched[caption] = schedule;
      sp[s].push_back(caption);
    }
  }
  cin >> m;
  while (m--) {
    vector<string> cities;
    cin >> k;
    while (k--) {
      cin >> s;
      cities.push_back(s);
    }
    good = false;
    vector<string> ans;
    for (int i = 0; (i < 24) && !good; i++) {
      ans.clear();
      good = true;
      for (int j = 0; (j < cities.size()) && good; j++) {
        good = false;
        for (int k = 0; k < sp[cities[j]].size(); k++) {
          if (sched[sp[cities[j]][k]][i] == '.') {
            ans.push_back(sp[cities[j]][k]);
            good = true;
            break;
          }
        }
      }
    }

    if (good) {
      cout << "Yes ";
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
      }
    } else {
      cout << "No";
    }
    cout << "\n";
  }
  return 0;
}
