// https://www.youtube.com/watch?v=nIVW4P8b1VA&ab_channel=NeetCode

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l, r, m, n, i, j, mn = nums[0];
        n = nums.size();
        l = 0;
        r = n-1;
        
        while (l <= r) {
            m = l + (r-l)/2;
            mn = min(mn, nums[m]);
            
            if (nums[l] <= nums[r]) {
                mn = min(mn, nums[l]);
                return mn;
            }
            else if (nums[l] <= nums[m]) {
                l = m+1;
            } else
                r = m-1;
        }
        return mn;
    }
};
