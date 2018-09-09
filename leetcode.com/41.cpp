class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        if (n == 0) {
            return 1;
        }

        while (l < r) {
            if (nums[l] > 0) {
                l++;
            } else {
                swap(nums[l], nums[r]);
                r--;
            }
        }

        if (nums[l] > 0) {
            l++;
        }

        if (l == 0) {
            return 1;
        }

        for (int i = 0; i < l; i++) {
            int q = abs(nums[i]) - 1;
            if (q < l) {
                if (nums[q] > 0) {
                    nums[q] = -nums[q];
                }
            }
        }

        for (int i = 0; i < l; i++) {
            if (nums[i] > 0) {
                return i+1;
            }
        }

        return l+1;

    }
};
