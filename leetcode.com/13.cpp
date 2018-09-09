class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int ans = 0;
        int local_max = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (m[s[i]] >= local_max) {
                ans += m[s[i]];
                local_max = m[s[i]];
            } else {
                ans -= m[s[i]];
            }
        }
        return ans;
    }
};
