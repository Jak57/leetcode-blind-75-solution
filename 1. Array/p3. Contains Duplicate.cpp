class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n, i, j;
        n = nums.size();
        for (i = 0; i < n; i++) {
            if (mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 1;
            else
                mp[nums[i]] += 1;
        }
        
        bool found = false;
        for (auto c: mp) {
            if (c.second >= 2) {
                found = true;
                break;
            }
        }
        return found;
    }
};
