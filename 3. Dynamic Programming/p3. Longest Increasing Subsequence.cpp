// DP
// https://www.youtube.com/watch?v=cjWnW0hdF1Y&ab_channel=NeetCode

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int i, j, n;
        int dp[10000];
        n = nums.size();
        memset(dp, 0, sizeof(dp));
        
        dp[n-1] = 1;
        for (i = n-2; i >= 0; i--) {
            dp[i] = 1;
            for (j = i; j < n; j++) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        
        int mx = 0;
        for (i = 0; i < n; i++)
            mx = max(mx, dp[i]);
        return mx;
    }
};
