class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        bool one = false;
        int mans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (one) {
                    mans++;
                } else {
                    one = true;
                    mans = 1;
                }
            } else {
                ans = max(ans, mans);
                mans = 0;
                one = false;
            }
        }
        return max(ans, mans);
    }
};
