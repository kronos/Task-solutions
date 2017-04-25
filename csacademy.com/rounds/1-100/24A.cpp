#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, o;
    cin >> n;
    int m = 0,c=0;
    for (int i = 0; i < n; i++) {
        cin >> o;
        if (o == 1) {
            c++;
        } else {
            c--;
        }
        m = max(m,c);
        c = max(c,0);
    }
    cout << m;
    return 0;
}
