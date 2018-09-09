class Solution {
    vector<int> arr;
    int n;
public:
    int peak(int l, int r) {
        int m = l + (r - l) / 2;

        if (m == 0 || (arr[m-1] < arr[m])) {
            if (m < n-1 && (arr[m+1] > arr[m])) {
                return peak(m+1,r);
            } else {
                return m;
            }
        } else {
            return peak(l,m-1);
        }
    }

    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        arr = nums;
        n = nums.size();

        int l = 0;
        return peak(0, n-1);
    }
};
