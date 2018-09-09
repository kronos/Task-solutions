class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }

        string s = needle + "#" + haystack;
        vector<int> pi(s.length());
        pi[0] = 0;
        for (int i = 1; i < s.length(); i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j-1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;
        }

        for (int i = needle.length() + 1; i < s.length(); i++) {
            if (pi[i] == needle.length()) {
                return i - needle.length()*2;
            }
        }
        return -1;
    }
};
