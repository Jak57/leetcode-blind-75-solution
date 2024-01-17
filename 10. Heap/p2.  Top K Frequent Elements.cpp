1.
// Heaps

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
