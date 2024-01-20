// Merge Intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n, i, j, x1, y1, x2, y2;
        n = intervals.size();
        
        if (n == 1)
            return intervals;
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        x1 = intervals[0][0];
        y1 = intervals[0][1];
        
        for (i = 1; i < n; i++) {
            x2 = intervals[i][0];
            y2 = intervals[i][1];
            
            if (y1 < x2) {
                ans.push_back({x1, y1});
                x1 = x2;
                y1 = y2;
            } else if (y2 < x1) {
                ans.push_back({x2, y2});
            } else {
                x1 = min(x1, x2);
                y1 = max(y1, y2);
            }
        }
        ans.push_back({x1, y1});
        return ans;
    }
};
