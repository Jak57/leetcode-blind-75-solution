class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i, j, n, l, r, m;
        n = nums.size();
        l = 0;
        r = n-1;
        
        while (l <= r) {
            m = l + (r-l)/2;
            if (nums[m] == target)
                return m;
            else if (nums[l] <= nums[m]) {
                if (target >= nums[l] && target <= nums[m])
                    r = m-1;
                else
                    l = m+1;
            } else {
                if (target >= nums[m] && target <= nums[r])
                    l = m+1;
                else
                    r = m-1;
            }
        }
        return -1;
    }
};
