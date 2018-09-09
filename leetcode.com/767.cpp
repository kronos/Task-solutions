class Solution {
    int a[26];

    int next(int ignore) {
        int imax = 0;
        if (ignore == 0) {
            imax = 1;
        }
        for (int i = 1; i < 26; i++) {
            if (i != ignore && a[i] > a[imax]) {
                imax = i;
            }
        }

        return imax;
    }
public:
    string reorganizeString(string S) {
        if (S == "") {
            return "";
        }
        for (int i = 0; i < 26; i++) {
            a[i] = 0;
        }
        int imax = 0, idx;
        int len = S.length();
        for (int i = 0; i < len; i++) {
            idx = S[i]-'a';
            a[idx]++;
            if (a[imax] < a[idx]) {
                imax = idx;
            }
        }
        if (a[imax] <= len/2+len%2) {
            string r = "";
            r += (imax+'a');
            int last = imax, q;
            a[imax]--;
            for (int i = 1; i < S.length(); i++) {
                q = next(last);
                r += ('a' + q);
                last = q;
                a[last]--;
            }
            return r;
        } else {
            return "";
        }
    }
};
