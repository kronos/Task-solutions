class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        ans[0] = 0;
        if (num == 0) {
            return ans;
        }
        ans[1] = 1;
        if (num == 1) {
            return ans;
        }
        ans[2] = 1;
        if (num == 2) {
            return ans;
        }
        unsigned prev,from,q;
        for (int step = 2; step < num;) {
            prev = step;
            step *= 2;
            q = step/2-1;
            if (num >= step) {
                from = step-1;
                ans[step] = 1;
            } else {
                from = num;
                q = q - (step-num) + 1;
            }
           // cout << from << " " << q << endl;
            for (int i = from; i > prev; i--, q--) {
                ans[i] = ans[q] + 1;
            }
        }
        return ans;
    }
};
