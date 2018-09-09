class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<int> req(256, 0);
        vector<int> fac(256, 0);
        for (auto c: t) {
            req[c]++;
        }

        int l = 0, r = 0, len = n+1, ansl = 0, cnt = 0;
        while (r < n) {
            if (req[s[r]]) {
                fac[s[r]]++;
                if (fac[s[r]] <= req[s[r]]) {
                    cnt++;
                }
                while (cnt == m) {
                    if (len > r - l + 1) {
                        ansl = l;
                        len = r - l + 1;
                    }

                    if (fac[s[l]]) {
                        fac[s[l]]--;
                        if (fac[s[l]] < req[s[l]]) {
                            cnt--;
                        }
                    }
                    l++;
                }
            }
            r++;
        }

        return (len == n + 1) ? "" : s.substr(ansl, len);
    }
};
