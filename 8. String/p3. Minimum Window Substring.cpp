// 01
// Minimum window substring
// https://www.youtube.com/watch?v=jSto0O4AJbM&t=1054s&ab_channel=NeetCode

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mps;
        map<char, int> mpt;
        int i, j, n, m;
        int cnt;
        char ch;
        
        n = s.size();
        m = t.size();
        for (i = 0; i < n; i++) {
            ch = s[i];
            if (mps.find(ch) == mps.end())
                mps[ch] = 1;
            else
                mps[ch]++;
        }
        
        for (i = 0; i < m; i++) {
            ch = t[i];
            if (mpt.find(ch) == mpt.end())
                mpt[ch] = 1;
            else
                mpt[ch]++;
        }
        
        map<char, int> window;
        int target = mpt.size(), count = 0;
        for (auto item: mpt) {
            ch = item.first;
            cnt = item.second;
            
            window[ch] = 0;
            if (mps.find(ch) == mps.end() || mps[ch] < cnt)
                return "";
        }
        
        int mxSize = INT_MAX;
        int ansi, ansj;
        string ans;
        i = 0;
        
        for (j = 0; j < n; j++) {
            ch = s[j];
            if (window.find(ch) != window.end()) {
                window[ch] += 1;
                if (window[ch] == mpt[ch])
                    count += 1;
            }
            
            while (count == target) {
                if ((j-i+1) < mxSize) {
                    mxSize = j-i+1;
                    ansi = i;
                    ansj = j;
                }
                
                ch = s[i];
                if (window.find(ch) != window.end()) {
                    window[ch] -= 1;
                    if (window[ch] < mpt[ch])
                        count -= 1;
                }
                i++;
            }
            
            while ((window.find(s[i]) == window.end()) && i < n)
                i++;   
        }
        
        ans = s.substr(ansi, ansj-ansi+1);
        return ans;
    }
};



// 02.

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mpt;
        int i, j, n, m;
        char ch;
        
        int count, target;
        int si, sj, minSize = INT_MAX, sz;
        bool found = false;
        
        map<char, int> window;
        n = s.size();
        m = t.size();
        
        for (i = 0; i < m; i++) {
            ch = t[i];
            if (mpt.find(ch) == mpt.end())
                mpt[ch] = 1;
            else
                mpt[ch] += 1;
        }
        
        for (auto item: mpt) {
            ch = item.first;
            window[ch] = 0;
        }
        
        target = mpt.size();
        count = 0;
        i = 0;
        
        for (j = 0; j < n; j++) {
            ch = s[j];
            if (window.find(ch) == window.end()) 
                continue;

            window[ch] += 1;
            if (window[ch] == mpt[ch])
                count += 1;
            
            while (count == target) {
                found = true;
                sz = j-i+1;
                if (sz < minSize) {
                    minSize = sz;
                    si = i;
                    sj = j;
                }
                
                ch = s[i];
                if (window.find(ch) != window.end()) {
                    window[ch] -= 1;
                
                    if (window[ch] < mpt[ch])
                        count -= 1;
                }
                i++;
            }
            while (i < n && (window.find(s[i]) == window.end()))
                i++;
        }
        
        if (!found)
            return "";
        else
            return s.substr(si, sj-si+1);
    }
};