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

// 02.
// Hashmap
// https://www.youtube.com/watch?v=vzdNOK2oB2E&ab_channel=NeetCode

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n, i, j;
        string s, tmp;
        char ch;
        
        vector<vector<string>> ans;
        map<map<char, int>, vector<string>> mp;
        n = strs.size();
        
        for (i = 0; i < n; i++) {
            s = strs[i];
            map<char, int> smallMp;
            for (j = 0; j < s.size(); j++) {
                ch = s[j];
                if (smallMp.find(ch) == smallMp.end())
                    smallMp[ch] = 1;
                else
                    smallMp[ch]++;
            }
            
            mp[smallMp].push_back(s);
        }

        for (auto item: mp) {
            ans.push_back(item.second);
        }
        
        return ans;
    }
};
