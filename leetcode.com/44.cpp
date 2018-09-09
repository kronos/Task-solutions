class Solution {
public:
    bool isMatch(string s, string p) {
        // T[i][j] s[i] <=> p[j]
        size_t n = s.length();
        size_t m = p.length();
        vector<vector<bool> > T(n+1, vector<bool>(m+1, false));

        T[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                T[0][j] = T[0][j - 1];
            } else {
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j-1] == '*') {
                    T[i][j] = T[i][j-1] || T[i-1][j];
                } else if (p[j-1] == '?' || p[j-1] == s[i-1]) {
                    T[i][j] = T[i-1][j-1];
                } else {
                    T[i][j] = false;
                }
            }
        }
        return T[n][m];
    }
};
