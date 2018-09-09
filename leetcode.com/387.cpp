class Solution {
public:
    int firstUniqChar(string s) {
        int ans = s.length();
        int p[26];
        bool g[26];
        for (int i = 0; i < 26; i++) {
            p[i] = -1;
            g[i] = false;
        }

        for (int i = 0; i < s.length(); i++) {
            if (p[s[i]-'a'] >= 0) {
                g[s[i]-'a'] = false;
            } else {
                g[s[i]-'a'] = true;
                p[s[i]-'a'] = i;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (g[i]) {
                ans = min(ans, p[i]);
            }
        }

        return ans == s.length() ? -1 : ans;
    }
};
