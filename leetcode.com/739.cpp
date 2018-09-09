class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        if (n == 0) {
            return ans;
        }

        map<int,int> m;
        m[t[n-1]] = n-1;
        for (int i = n-2; i >= 0; i--) {
            for (int j = t[i] + 1; j <= 100; j++) {
                auto it = m.find(j);
                if (it != m.end()) {
                    if (ans[i]) {
                        ans[i] = min(ans[i], it->second-i);
                    } else {
                        ans[i] = it->second-i;
                    }
                }
            }

            m[t[i]] = i;
        }
        return ans;
    }
};
