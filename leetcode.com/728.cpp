class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> r;
        int n;
        bool sd;
        for (int i = left; i <= right; i++) {
            n = i;
            sd = true;

            while (sd && n > 0) {
                sd = (n % 10 != 0) && i % (n % 10) == 0;
                n /= 10;
            }

            if (sd) {
                r.push_back(i);
            }
        }

        return r;
    }
};
