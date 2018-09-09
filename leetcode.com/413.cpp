class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) {
            return 0;
        }
        int ans = 0, d,q;
        for (int i = 0; i < n-2;) {
            d = A[i] - A[i+1];
            if (d == A[i+1] - A[i+2]) {
               int j = i + 2;
               for (; j < n-1; j++) {
                   if (d != A[j] - A[j+1]) {
                       break;
                   }
               }
               q = j - i + 1;
               ans += (1 + (q-2))*(q-2)/2;
               i = j;
            } else {
                 i++;
            }
        }


        return ans;
    }
};
