class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        int dp[A.size() + 1] = {0};
        for (int i = 1; i <= A.size(); i++) {
            int m = A[i - 1];
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    m = max(m,A[i - j]);
                    dp[i] = max(dp[i],dp[i - j] + m*j);
                }
            }
        }
        return dp[A.size()];
    }
};
