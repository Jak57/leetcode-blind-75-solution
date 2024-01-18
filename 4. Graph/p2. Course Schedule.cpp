// Tree DFS

class Solution {
public:
    bool found = false;
    vector<int> adj[2005];
    
    void cycle(int src, char *visited) {
        visited[src] = 'g';
        int i;
        
        for (i = 0; i < adj[src].size(); i++) {
            int child = adj[src][i];
            if (visited[child] == 'w') 
                cycle(child, visited);
            else if (visited[child] == 'g')
                found = true;
        }
        visited[src] = 'b';
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n, i, j, u, v;
        char visited[2005];
        n = prerequisites.size();
        
        for (i = 0; i < n; i++) {
            v = prerequisites[i][0];
            u = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        for (i = 0; i < numCourses; i++)
            visited[i] = 'w';
        
        for (i = 0; i < numCourses; i++) {
            if (visited[i] == 'w' && !found) {
                cycle(i, visited);
            }
        }
        
        return !found;
    }
};
