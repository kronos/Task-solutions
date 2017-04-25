#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
bool special[1001];
int xx[1001];
int yy[1001];
vector<int> specials;
vector<int>::iterator it;

int main() {
    int n, t, i, j;
    int s, x, y, q;
    cin >> n >> t;

    for (i = 1; i <= n; i++) {
        cin >> s >> xx[i] >> yy[i];
        special[i] = s == 1;
        if (special[i]) {
            specials.push_back(i);
        }
    }

    cin >> q;
    int dist;
    while (q--) {
        cin >> i >> j;
        dist = abs(xx[i] - xx[j]) + abs(yy[i] - yy[j]);

        if (special[i] && special[j]) {
            dist = min(dist, t);
        } else {
            int dist1 = 1e9, dist2 = 1e9, b;
            for (it = specials.begin(); it != specials.end(); it++) {
                b = abs(xx[i] - xx[*it]) + abs(yy[i] - yy[*it]);
                if (b < dist1) {
                    dist1 = b;
                }

                b = abs(xx[*it] - xx[j]) + abs(yy[*it] - yy[j]);
                if (b < dist2) {
                    dist2 = b;
                }
            }

            dist = min(dist, dist1 + dist2 + t);
        }
        cout << dist << "\n";
    }
    return 0;
}
