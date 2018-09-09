class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> r(S.length(), 10001);
        int i = 0, kk = 10001;
        while (i < S.length()) {
            if (S[i] == C) {
                r[i] = 0;
                int j = i-1, k = 0;
                while (j >= 0 && r[j] > k + 1) {
                    r[j] = k + 1;
                    j--;
                    k++;
                }
                kk = 1;
            } else {
                r[i] = kk;
                kk++;
            }
            i++;
        }
        return r;
    }
};
