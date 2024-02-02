// Sliding window

class Solution {
public:
    int findMx(map<char, int> mp) {
        int mx = 0;
        for (auto item: mp)
            mx = max(mx, item.second);
        return mx;
    }
    
    int characterReplacement(string s, int k) {
        int i, j, n;
        int windowSize, mxCount;
        map<char, int> mp;
        char ch;
        n = s.size();
        
        i = 0;
        int ans = 0;
        for (j = 0; j < n; j++) {
            ch = s[j];
            if (mp.find(ch) == mp.end())
                mp[ch] = 1;
            else
                mp[ch]++;
            
            windowSize = j-i+1;
            mxCount = findMx(mp);
            if (windowSize-mxCount <= k) {
                ans = max(ans, windowSize);
            } else {
                while (true) {
                    ch = s[i];
                    mp[ch]--;
                    i++;
                    
                    windowSize = j-i+1;
                    mxCount = findMx(mp);
                    if (windowSize-mxCount <= k)
                        break;
                }
            }
        }
        return ans;
    }
};
