class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n, i, j;
        n = nums.size();
        vector<int> pre(n);
        int prod = 1;
        
        for (i = 0; i < n; i++) {
            prod *= nums[i];
            pre[i] = prod;
        }
        
        prod = 1;
        for (i = n-1; i >= 0; i--) {
            if (i == n-1) {
                pre[i] = pre[i-1];
            } else if (i == 0) {
                pre[i] = prod;
            } else {
                pre[i] = pre[i-1]*prod;
            }
            
            prod *= nums[i];
        }
        return pre;
        
    }
};
