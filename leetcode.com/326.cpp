class Solution {
public:
    bool isPowerOfThree(int n) {
        bool ans = n > 0;
        while (n > 1 && ans) {
            ans = n % 3 == 0;
            n /= 3;
        }
        return ans;
    }
};
