class Solution {
public:
    int titleToNumber(string s) {
      int r = 0, q = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
          r += (s[i] - 'A' + 1)*q;
          q*=26;
        }
      return r;
    }
};
