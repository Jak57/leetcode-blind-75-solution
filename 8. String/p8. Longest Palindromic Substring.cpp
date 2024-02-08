// 01.
// Sliding window
// https://www.youtube.com/watch?v=XYQecbcd6_c&t=307s&ab_channel=NeetCode

class Solution {
public:
    bool inLimit(int i, int j, int n) {
        return ((i >= 0 && i < n) && (j >= 0 && j < n));
    }
    string longestPalindrome(string s) {
        int i, j, n, sz, l, r, ansi = -1, ansj = -1;
        int mxWindow = 0;
        n = s.size();
        
        for (i = 0; i < n; i++) {
            l = i;
            r = i;
            
            while (inLimit(l, r, n) && (s[l] == s[r])) {
                sz = r-l+1;
                if (sz > mxWindow) {
                    mxWindow = sz;
                    ansi = l;
                    ansj = r;
                }
                l--;
                r++;
            }
            
            // even length
            l = i;
            r = i+1;
            
            while (inLimit(l, r, n) && (s[l] == s[r])) {
                sz = r-l+1;
                if (sz > mxWindow) {
                    mxWindow = sz;
                    ansi = l;
                    ansj = r;
                }
                l--;
                r++;
            }
        }
        
        return s.substr(ansi, ansj-ansi+1);
    }
};
