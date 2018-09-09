class Solution {
public:
    int mySqrt(int x) {
        double l = 1.0;
        double r = (double)x;
        double mid = x;
        while (r-l > 1e-6) {
            mid = l + (r-l)/2.0;
            if (mid*mid < x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
    }
};
