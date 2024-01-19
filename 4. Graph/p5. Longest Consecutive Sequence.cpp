// Hash Map
// https://www.youtube.com/watch?v=P6RZZMu_maU&ab_channel=NeetCode

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n, i, j, mx, cnt, val;
        mx = 0;
        n = nums.size();
        
        if (n == 0)
            return 0;
        
        unordered_map<int, int> mp;
        for (i = 0; i < n; i++) {
            val = nums[i];
            if (mp.find(val) == mp.end())
                mp[val] = 1;
        }
        
        for (i = 0; i < n; i++) {
            val = nums[i];
            if (mp.find(val-1) != mp.end())
                continue;
                
            cnt = 0;
            while (mp.find(val) != mp.end()) {
                cnt += 1;
                val++;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};
