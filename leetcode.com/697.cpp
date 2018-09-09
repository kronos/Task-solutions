class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int d[50000];
        int f[50000];
        int l[50000];

        int n = nums.size();
        int degree = 0;

        for (int i = 0; i < 50000; i++) {
            d[i] = 0;
            f[i] = l[i] = -1;
        }

        for (int i = 0; i < n; i++) {
            if (f[nums[i]] == -1) {
                f[nums[i]] = i;
            }
            l[nums[i]] = i;
            d[nums[i]]++;
            degree = max(degree, d[nums[i]]);
        }

        int distance = 50001;
        for (int i = 0; i < 50000; i++) {
            if (d[i] == degree && l[i] - f[i] < distance) {
                //cout << i << " " << l[i] << " " << f[i] << endl;
                distance = l[i] - f[i];
            }
        }

        return distance + 1;
    }
};
