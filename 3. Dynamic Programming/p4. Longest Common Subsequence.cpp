// DP

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i, j, n, m;
        text1 = 'A' + text1;
        text2 = 'B' + text2;
        n = text1.size();
        m = text2.size();
        
        int dp[1005][1005];
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= m; j++)
                dp[i][j] = 0;
        }
        
        for (i = 1; i < n; i++) {
            for (j = 1; j < m; j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
