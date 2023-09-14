class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n, i, j, prod;
        n = nums.size();
        vector<int> ans;
        prod = 1;
        int cnt = 0;
        
        int nonzero_prod = 1;
        for (i = 0; i < n; i++) {
            if (nums[i] == 0)
                cnt++;
            else
                nonzero_prod *= nums[i];
                
        }
        
        if (cnt == 0) {
            for (i = 0; i < n; i++) {
                ans.push_back(nonzero_prod/nums[i]);
            }
        } else {
            if (cnt > 1) {
                for (i = 0; i < n; i++) {
                    ans.push_back(0);
                }
            } else {
                for (i = 0; i < n; i++) {
                    if (nums[i] == 0)
                        ans.push_back(nonzero_prod);
                    else
                        ans.push_back(0);
                }
            }
        }
        return ans;
    }
};

/********** solution 02 ***************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n, i, j, prod;
        n = nums.size();
        int prefix[n+5], suffix[n+5];
        prefix[0] = 1;
        suffix[n-1] = 1;
        for (i = 1; i < n; i++)
            prefix[i] = prefix[i-1] * nums[i-1];
        for (i = n-2; i >= 0; i--)
            suffix[i] = suffix[i+1] * nums[i+1];
        vector<int> ans;
        for (i = 0; i < n; i++)
            ans.push_back(prefix[i]*suffix[i]);
        return ans;
    }
};
