// Tree BFS

class Solution {
public:
    int n, m;
    bool pacific, atlantic;
    int visited[205][205];
    
    bool inLimit(int r, int c) {
        return ((r >= 0 && r < n) && (c >= 0 && c < m));
    }
    
    void bfs(int r, int c, vector<vector<int>>& heights) {
        int h, i, j, newX, newY, newH;
        visited[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        
        while (!q.empty()) {
            r = q.front().first;
            c = q.front().second;
            h = heights[r][c];
            q.pop();
            
            if ((r == n-1 && c == 0) || (r == 0 && c == m-1)) {
                pacific = true;
                atlantic = true;
            } else {

                if (r == 0 || c == 0) 
                    pacific = true;

                if (c == m-1 || r == n-1)
                    atlantic = true;
            }
            
            int x[4] = {-1, 0, 1, 0};
            int y[4] = {0, 1, 0, -1};
            
            for (i = 0; i < 4; i++) {
                newX = r + x[i];
                newY = c + y[i];
                
                if (inLimit(newX, newY) && h >= heights[newX][newY] && visited[newX][newY] == 0) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }   
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int i, j;
        vector<vector<int>> ans;
        n = heights.size();
        m = heights[0].size();
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                
                for (int u = 0; u < n; u++) {
                    for (int v = 0; v < m; v++)
                        visited[u][v] = 0;
                }

                pacific = false;
                atlantic = false;
                bfs(i, j, heights);

                if (pacific & atlantic) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};
