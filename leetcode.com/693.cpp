class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool ans = true;
        int prev = -1;
        while (n > 0 && ans) {
            int t = n & 1;
            n >>= 1;
            ans = prev != t;
            prev = t;
        }
        return ans;
    }
};
