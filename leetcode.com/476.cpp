class Solution {
public:
    int findComplement(int num) {
        long long x = 1;
        while (x < num) {
            x*= 2;
        }
        return ~num & (x-1);
    }
};
