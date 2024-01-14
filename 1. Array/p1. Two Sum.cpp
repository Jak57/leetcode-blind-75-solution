// https://www.youtube.com/watch?v=KLlXCFG5TnA&t=3s&ab_channel=NeetCode

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j, n, rem;
        unordered_map< int, vector<int> > mp;
        vector<int> ans;
        
        n = nums.size();
        for (i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        for (i = 0; i < n; i++) {
            rem = target - nums[i];
            if (mp.find(rem) != mp.end()) {
                if ((rem == nums[i]) && (mp[rem].size() >= 2)) {
                    ans = {mp[rem][0], mp[rem][1]};
                    break;
                }
                else if (rem != nums[i]) {
                    ans = {mp[nums[i]][0], mp[rem][0]};
                    break;
                }
            }
        }
        
        return ans;
    }
};
