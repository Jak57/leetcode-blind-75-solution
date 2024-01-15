// https://www.youtube.com/watch?v=jzZsG8n2R9A&ab_channel=NeetCode

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n, i, j, a, b, c, l, r, target;
        n = nums.size();
        
        sort(nums.begin(), nums.end());
        for (i = 0; i < n; i++) {
            if (i > 0 && nums[i-1] == nums[i])
                continue;
            
            a = nums[i];
            l = i+1;
            r = n-1;
            target = -a;
            
            while (l < r) {
                if (nums[l]+nums[r] == target) {
                    vector<int>tmp = {a, nums[l], nums[r]};
                    ans.push_back(tmp);
                    l++;
                    
                    while (l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                    
                } else if (nums[l] + nums[r] < target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};
