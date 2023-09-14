class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n, i, j;
        vector<int> v = nums;
        int local_max = v[0], global_max = v[0];
        n = v.size();

        for (i = 1; i < n; i++) {
            local_max = max(v[i], v[i] + local_max);
            if (local_max > global_max)
                global_max = local_max;
        }

        return global_max;
        
    }
};
