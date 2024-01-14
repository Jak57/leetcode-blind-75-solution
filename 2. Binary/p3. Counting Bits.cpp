// https://www.youtube.com/watch?v=awxaRgUB4Kw&ab_channel=Techdose

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;
        
        int i, j;
        for (i = 1; i <= n; i++) {
            ans[i] = ans[i/2];
            if (i%2 == 1) 
                ans[i]++;
        }
        return ans;
    }
};
