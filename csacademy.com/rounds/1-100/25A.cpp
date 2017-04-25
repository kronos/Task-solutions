#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int a[1000];
long sum;

int main() {
    bool found = false;
    int n, idx;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; (i < n) && !found; i++) {
        if ((sum - a[i] - a[i] == 0)) {
            found = true;
            idx = 1 + i;
        }
    }

    if (found) {
        cout << idx;
    } else {
        cout << -1;
    }
    return 0;
}
