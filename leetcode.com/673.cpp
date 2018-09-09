class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int L[2000];
        int ways[2000];
        int len = nums.size();
        int ans = 1;
        for (int i = 0; i < len; i++) {
            L[i] = 1;
            ways[i] = 1;
        }
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (L[j] + 1 > L[i]) {
                        L[i] = L[j] + 1;
                        ans = max(ans, L[i]);
                        ways[i] = ways[j];
                    } else if (L[j] + 1 == L[i]) {
                        ways[i] += ways[j];
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (L[i] == ans) {
                sum += ways[i];
            }
        }
        return sum;
    }
};
