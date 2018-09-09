
void count_sort(vector<int>& v, int offset) {
    size_t n = v.size();
    vector<int> output(n);
    vector<int> count(256, 0);

    for (int i = 0; i < n; i++) {
        count[(v[i] >> offset) & 0xFF]++;
    }

    for (int i = 1; i < 256; i++) {
        count[i] += count[i-1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(v[i] >> offset) & 0xFF] - 1] = v[i];
        count[(v[i] >> offset) & 0xFF]--;
    }

    for (int i = 0; i < n; i++) {
        v[i] = output[i];
    }
}


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        for (int offset = 0; offset < 32; offset +=8) {
            count_sort(nums, offset);
        }
        int ans = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); i++) {
            ans = max(ans, nums[i] - nums[i-1]);
        }
        return ans;
    }
};
