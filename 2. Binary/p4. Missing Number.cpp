// https://dev-staging00.medium.com/cyclic-sort-programming-pattern-16eb16ac9c4b

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i, j, n;
        n = nums.size();
        for (i = 0; i < n; i++) {
            while (nums[i] < n && nums[nums[i]] != nums[i]) {
                int tmp = nums[i];
                nums[i] = nums[nums[i]];
                nums[tmp] = tmp;
            }
        }
        
        int ans;
        for (i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
