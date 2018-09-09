class Solution {
public:
    bool isPowerOfFour(int num) {
        bool ans = (num > 0) && ((num & (num-1)) == 0);
        while (num > 1 && ans) {
            ans = num % 4 == 0;
            num /= 4;
        }

        return ans;
    }
};
