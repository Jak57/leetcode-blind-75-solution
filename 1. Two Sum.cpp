class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n, i, j;
        vector<int> v = nums;
        vector<int> id(2);
        bool found = false;
        n = v.size();

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if ((i != j) && (v[i] + v[j] == target)) {
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        id[0] = i;
        id[1] = j;
        return id;
    }
};
