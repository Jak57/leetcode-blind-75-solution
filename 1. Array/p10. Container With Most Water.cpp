// https://www.youtube.com/watch?v=UuiTKBwPgAo&ab_channel=NeetCode
// Two Pointers

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n, i, j, mx = 0, minHeight;
        n = height.size();
        int l, r;
        
        l = 0;
        r = n-1;
        while (l < r) {
            minHeight = min(height[l], height[r]);
            mx = max(mx, (r-l)*minHeight);
            if (height[l] == minHeight)
                l++;
            else
                r--;
        }
        return mx;
    }
};
