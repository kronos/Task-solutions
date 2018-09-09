class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> r(n);
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                r[i-1] = "FizzBuzz";
            } else if (i%5 == 0) {
                r[i-1] = "Buzz";
            } else if (i%3 == 0) {
                r[i-1] = "Fizz";
            } else {
                r[i-1] = to_string(i);
            }
        }

        return r;
    }
};
