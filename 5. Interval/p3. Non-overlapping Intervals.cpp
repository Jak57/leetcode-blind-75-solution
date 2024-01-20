// Merge Interval

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n, i, j, x1, y1, x2, y2;
        n = intervals.size();
        sort(intervals.begin(), intervals.end());
        if (n == 1)
            return 0;
        
        x1 = intervals[0][0];
        y1 = intervals[0][1];
        int cnt = 0;
        
        for (i = 1; i < n; i++) {
            x2 = intervals[i][0];
            y2 = intervals[i][1];
            
            if (y1 <= x2) {
                x1 = x2;
                y1 = y2;
            } else {
                if (y2 < y1) {
                    x1 = x2;
                    y1 = y2;
                }
                cnt++;
            }
        }
        return cnt;
    }
};
