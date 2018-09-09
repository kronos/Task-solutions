class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") {
            return "";
        }
        int mi, len;
        mi = 0; len = 1;
        bool table[1000][1000];
        int n = s.length();
        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            table[i][i+1] = s[i] == s[i+1];
            if (table[i][i+1]) {
                mi = i; len = 2;
            }
        }

        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                int j = i+k-1;
                table[i][j] = table[i+1][j-1] && s[i] == s[j];
                if (table[i][j] && i+j+1 > len) {
                    mi = i; len = j-i+1;
                }
            }
        }
        return s.substr(mi, len);
    }
};
