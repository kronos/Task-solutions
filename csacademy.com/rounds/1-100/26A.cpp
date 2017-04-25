#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,k;
    string s;
    cin >> n >> k;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        bool a[27];
        for (int j = 0; j < 27; j++) {
            a[j] = false;
        }
        cin >> s;
        if (s.length() > answer) {
            int cnt = 0;
            for (int j = 0; (j < s.length()) && (cnt <= k); j++) {
                if (!a[s[j]-'a']) {
                    a[s[j]-'a'] = true;
                    cnt++;
                }
            }

            if (cnt <= k) {
                answer = s.length();
            }
        }
    }
    if (answer == 0) {
        answer--;
    }
    cout << answer;
    return 0;
}
