1.
// Heap

struct Node{
    int val;
    int cnt;
};

class cmp{
    public:
    bool operator()(Node a, Node b) {
        return (a.cnt < b.cnt);
    }
    
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int val, num;
        priority_queue<Node, vector<Node>, cmp> pq;
        
        int i, j, n;
        n = nums.size();
        
        for (i = 0; i < n; i++) {
            val = nums[i];
            if (mp.find(val) == mp.end())
                mp[val] = 1;
            else
                mp[val] += 1;
        }
        
        for (auto item: mp) {
            Node tmp;
            tmp.val = item.first;
            tmp.cnt = item.second;
            pq.push(tmp);
        }
        
        vector<int> ans;
        while (!pq.empty() && k > 0) {
            ans.push_back(pq.top().val);
            k--;
            pq.pop();
        }
        
        return ans;
    }
};


2.
// Hash map
    
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n, i, j, val, cnt;
        n = nums.size();
        unordered_map<int, int> mp1;
        unordered_map< int, vector<int> > mp2;
        vector<int> ans;
        
        for (i = 0; i < n; i++) {
            val = nums[i];
            if (mp1.find(val) == mp1.end()) 
                mp1[val] = 1;
            else
                mp1[val] += 1;
        }
        
        for (auto item: mp1) {
            val = item.first;
            cnt = item.second;
            mp2[cnt].push_back(val);
        }
        
        for (i = n; i >= 1; i--) {
            if (mp2.find(i) != mp2.end()) {
                for (j = 0; j < mp2[i].size(); j++) {
                    if (k > 0)
                    {
                        ans.push_back(mp2[i][j]);
                        k--;
                    }
                }
            }
        }
        
        return ans;
    }
};
