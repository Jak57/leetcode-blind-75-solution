// Sliding window

class Solution {
public:
    bool inLimit(int i, int j, int n) {
        return ((i >= 0 && i < n) && (j >= 0 && j < n));
    }
    int numPalindrome(string s, int l, int r, int n) {
        int cnt = 0;
        while (inLimit(l, r, n) && (s[l] == s[r])) {
            cnt += 1;
            l--;
            r++;
        }
        return cnt;
    }
    
    int countSubstrings(string s) {
        int n, i, j, count = 0;
        int l, r;
        n = s.size();
        
        for (i = 0; i < n; i++) {
            // odd length
            l = i;
            r = i;
            count += numPalindrome(s, l, r, n);
            
            // even length
            l = i;
            r = i+1;
            count += numPalindrome(s, l, r, n);
        }
        return count;
    }
};
