// Sliding window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j, n, mx = 0;
        n = s.size();
        map<int, int> mp;
        if (n <= 1)
            return n;
        
        i = 0;
        j = 0;
        for (j = 0; j < n; j++) {
            char ch = s[j];
            if (mp.find(ch) == mp.end()) {
                mp[ch] = 1;
            } else {
                while (s[i] != ch) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) 
                        mp.erase(s[i]);
                    i++;
                }
                i++;
            }
            int sz = mp.size();
            mx = max(mx, sz);
        }
        return mx;
    }
};
