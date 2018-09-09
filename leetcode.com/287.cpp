class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = nums[0], j = nums[0];
        do {
            i = nums[i];
            j = nums[nums[j]];
        } while (i != j);

        int q = nums[0];
        int p = i;
        while (q != p) {
            q = nums[q];
            p = nums[p];
        }

        return p;
    }
};
