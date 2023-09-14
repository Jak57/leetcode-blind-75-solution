class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n, i, j, mn = INT_MAX;
        n = prices.size();
        int mx = 0;

        for (i = 0; i < n; i++) {
            mn = min(mn, prices[i]);
            mx = max(mx, prices[i] - mn);
        }
        return mx;
    }
};
