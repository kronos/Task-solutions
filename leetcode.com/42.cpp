class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (!n) {
            return 0;
        }

        int ans = 0;
        stack<int> st;
        int m = height[0];
        st.push(m);
        for (int i = 1; i < n; i++) {
            if (m <= height[i]) {
               while (st.size()) {
                   ans += m - st.top();
                   st.pop();
               }
              m = height[i];
            }
            st.push(height[i]);
        }

        if (st.size()) {
            m = st.top();
            st.pop();
            while (st.size()) {
                if (st.top() < m) {
                    ans += m - st.top();
                } else {
                    m = st.top();
                }
                st.pop();
            }
        }
        return ans;
    }
};
