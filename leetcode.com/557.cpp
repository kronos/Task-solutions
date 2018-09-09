class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        int len = s.length();
        string ss = s;
        char c;
        while (i < len) {
            j = i+1;
            while (j < len && s[j] != ' ') {
                j++;
            }

            for (int k = 0; k < (j-i)/2; k++) {
               c = ss[k+i];
               ss[k+i] = ss[j-1-k];
               ss[j-1-k] = c;
            }

            i = j + 1;
        }
        return ss;
    }
};
