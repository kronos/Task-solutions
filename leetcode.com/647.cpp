class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = s.length();

        int table[1000][1000];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                table[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            table[i][i] = true;
            if (i > 0 && s[i-1] == s[i]) {
                ans++;
                table[i-1][i] = true;
            }
        }

        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;
                if (s[i] == s[j] && table[i+1][j-1]) {
                    ans++;
                    table[i][j] = true;
                }
            }
        }
        return ans;
    }
};
