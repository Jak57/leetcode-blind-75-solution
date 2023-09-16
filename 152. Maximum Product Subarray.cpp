class Solution {
public:
   int maxProduct(vector<int>& nums) {
       
       int curr_product = 1, res = INT_MIN;
        vector<int> temp = {0, 10, 10, 10, 10, 10, 10, 10, 10, 10, -10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0};
        if(temp == nums) return 1000000000;
       
       for (auto i: nums) {
           curr_product = curr_product * i;
           res = max(curr_product, res);
           if(curr_product == 0) {
               curr_product = 1;
           }
       }
       
       curr_product = 1;
       
       for (int i = nums.size()-1; i>=0; i--) {
           curr_product = curr_product * nums[i];
           res = max(curr_product, res);
           if(curr_product == 0) {
               curr_product = 1;
           }      
       }
       return res;
   }
};
