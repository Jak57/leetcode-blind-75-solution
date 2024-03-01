// DP

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int i, j, n = coins.size();
        int val, rem;
        int mx = 100000000;
        int dp[amount+1];
        
        dp[0] = 0;
        for (i = 1; i <= amount; i++)
            dp[i] = mx;
        
        for (i = 0; i < n; i++) {
            val = coins[i];
            for (j = 1; j <= amount; j++) {
                rem = j - val;
                if (rem < 0)
                    continue;
                
                dp[j] = min(dp[j], dp[rem]+1);
            }
        }
        
        if (dp[amount] == 100000000)
            return -1;
        return dp[amount];
    }
};
