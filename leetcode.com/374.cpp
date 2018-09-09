// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        int mid, t;
        while (l <= r) {
            mid = l + (r-l)/2;
            t = guess(mid);
            if (t) {
                if (t == -1) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                return mid;
            }
        }
        return -1;
    }
};
