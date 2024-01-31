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
