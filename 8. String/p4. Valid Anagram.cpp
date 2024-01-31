// 1.

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n, m, i, j;
        n = s.size();
        m = t.size();
        if (n != m)
            return false;
        
        int arr1[26], arr2[26];
        memset(arr1, 0, sizeof(arr1));
        memset(arr2, 0, sizeof(arr2));
        
        int idx;
        for (i = 0; i < n; i++) {
            idx = s[i] - 'a';
            arr1[idx]++;
        }
        
        for (i = 0; i < m; i++) {
            idx = t[i] - 'a';
            arr2[idx]++;
        }
        
        for (i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
};


// 2.
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n, m, i;
        n = s.size();
        m = t.size();
        if (n != m)
            return false;
        
        map<char, int> mp;
        for (i = 0; i < n; i++) {
            char ch = s[i];
            if (mp.find(ch) == mp.end())
                mp[ch] = 1;
            else
                mp[ch]++;
        }
        
        for (i = 0; i < m; i++) {
            char ch = t[i];
            if (mp.find(ch) == mp.end()) {
                return false;
            } else {
                mp[ch]--;
                if (mp[ch] == 0)
                    mp.erase(ch);
            }
        }

        return true;
    }
};

// 3.
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n, m, i;
        n = s.size();
        m = t.size();
        if (n != m)
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
    }
};
