// Merge Interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i, j, n, x1, y1, x2, y2;
        n = intervals.size();
        vector<vector<int>> ans;
        
        if (n == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        
        x1 = newInterval[0];
        y1 = newInterval[1];
        
        for (i = 0; i < n; i++) {
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
