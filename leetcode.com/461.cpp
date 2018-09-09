class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        int xored = x^y;
        while (xored != 0) {
            result += xored & 1;
            xored >>= 1;
        }
        return result;
    }
};
