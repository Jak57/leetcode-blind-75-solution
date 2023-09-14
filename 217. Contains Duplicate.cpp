class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n, i;
        set<int> s;
        n = nums.size();
        for (i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }

        return !(s.size() == n);
    }
};
