// 01.
// Hashmap

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n, i, j;
        string s, tmp;
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        n = strs.size();
        
        for (i = 0; i < n; i++) {
            s = strs[i];
            tmp = s;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(s);
        }
        for (auto item: mp) {
            ans.push_back(item.second);
        }
        
        return ans;
    }
};
