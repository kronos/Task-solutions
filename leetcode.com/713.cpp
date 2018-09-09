class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p = 1;
        int ans = 0;
        int pos = 0, len = 0;
        for (int i = 0; i < nums.size(); i++) {
            p *= nums[i];
            if (p >= k) {
                if (nums[i] < k) {
                    while (pos <= i && p >= k) {
                        p /= nums[pos];
                        pos++;
                        len--;
                    }
                    len++;
                    ans += len;
                } else {
                    len = 0;
                    p = 1;
                    pos = i+1;
                }
            } else {
                len++;
                ans += len;
            }
        }
        return ans;
    }
};
