#include <iostream>

using namespace std;
    bool a[1001];

int main() {
    int n,x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x] = true;
    }
    for (int i = 1; i <= 1001; i++) {
        if (!a[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}
