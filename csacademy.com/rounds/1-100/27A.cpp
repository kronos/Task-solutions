#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
int a,b,n,x;
int items[100];
int main() {
    cin >> a >> b >> n;
    int fit = n;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (a >= b) {
        if (a >= x) {
            a-= x;
            fit--;
        }
      } else {
        if (b >= x) {
            b -= x;
            fit--;
        }
      }
    }

    cout << fit << endl;
    return 0;
}
