class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local_mx = -100000;
        int global_mx = -100000;
        int i, n = nums.size();
        
        for (i = 0; i < n; i++) {
            local_mx = max(nums[i], local_mx+nums[i]);
            global_mx = max(global_mx, local_mx);
        }
        return global_mx;
    }
};
