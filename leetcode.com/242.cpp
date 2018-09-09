class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int sd[26];
        int td[26];
        for (int i = 0; i < 26; i++) {
            sd[i] = td[i] = 0;
        }
        for (int i = 0; i < s.length(); i++) {
            sd[s[i]-'a']++;
            td[t[i]-'a']++;
        }
        bool good = true;
        for (int i = 0; good && (i < 26); i++) {
            good = sd[i] == td[i];
        }
        return good;
    }
};
