// https://www.youtube.com/watch?v=1pkOgXD63yU&ab_channel=NeetCode

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = -1, ans = 0;
        int n = prices.size();
        for (int i = n-1; i >= 0; i--) {
            mx = max(mx, prices[i]);
            ans = max(ans, mx-prices[i]);
        }
        return ans;
    }
};
