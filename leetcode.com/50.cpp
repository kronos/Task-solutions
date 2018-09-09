class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            if (n == -2147483648) {
                double r = myPow(x, -(n/2));
                return 1.0/(r*r);
            } else {
                return 1.0/(myPow(x, -n));
            }
        } else if (n == 0) {
            return 1.0;
        }

        if (n%2) {
            return x*myPow(x,n-1);
        }

        double r = myPow(x, n/2);
        return r*r;
    }
};
