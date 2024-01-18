// Tree BFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        
        int i;
        int visited[200];
        queue<Node*> q;
        set<int> s;
        vector<pair<int, int>> p;
        unordered_map<int, int> mp;
        
        
        s.insert(node->val);
        q.push(node);
        memset(visited, 0, sizeof(visited));
        
        while (!q.empty()) {
            Node* src = q.front();
            visited[src->val] = 1;
            q.pop();
            
            for (i = 0; i < src->neighbors.size(); i++) {
                if (visited[src->neighbors[i]->val] == 0) {
                    s.insert(src->neighbors[i]->val);
                    p.push_back(make_pair(src->val, src->neighbors[i]->val));
                    q.push(src->neighbors[i]);
                }
            }
        }
        
        vector<Node*> v(s.size());
        for (i = 0; i < s.size(); i++) {
            v[i] = new Node(i+1);
        }
        
        int x, y;
        for (i = 0; i < p.size(); i++) {
            x = p[i].first-1;
            y = p[i].second-1;
            v[x]->neighbors.push_back(v[y]);
            v[y]->neighbors.push_back(v[x]);
        }
            
        return v[0];
    }
};
