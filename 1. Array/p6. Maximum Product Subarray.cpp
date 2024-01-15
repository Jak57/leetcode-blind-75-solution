class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n, i;
        n = nums.size();
        int res = INT_MIN;
        int prod = 1;
        
        for (i = 0; i < n; i++) {
            prod *= nums[i];
            res = max(res, prod);
            if (prod == 0 || prod >= int(pow(10, 9)))
                prod = 1;
        }
        
        prod = 1;
        for (i = n-1; i >= 0; i--) {
            prod *= nums[i];
            res = max(res, prod);
            if (prod == 0 || prod >= int(pow(10, 9)))
                prod = 1;
        }
        
        return res;
    }
};
