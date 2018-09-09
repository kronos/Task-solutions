class Solution {
public:
    string reverseString(string s) {
        string ss = s;
        int len = s.length();
        char c;
        for (int i = 0; i < len/2; i++) {
            c = ss[i];
            ss[i] = ss[len-1-i];
            ss[len-1-i] = c;
        }
        return ss;
    }
};
