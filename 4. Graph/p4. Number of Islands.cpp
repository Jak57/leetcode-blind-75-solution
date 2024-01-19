// Tree BFS

class Solution {
public:
    int visited[305][305];
    int m, n;
    
    bool inLimit(int r, int c) {
        return ((r >= 0 && r < n) && (c >= 0 && c < m));
    }
    
    void bfs(int r, int c, vector<vector<char>>& grid) {
        int newX, newY, i, j;
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = 1;
        
        while (!q.empty()) {
            r = q.front().first;
            c = q.front().second;
            q.pop();
            
            int x[4] = {-1, 0, 1, 0};
            int y[4] = {0, 1, 0, -1};
            
            for (i = 0; i < 4; i++) {
                newX = r + x[i];
                newY = c + y[i];
                
                if (inLimit(newX, newY) && grid[newX][newY] == '1' && visited[newX][newY] == 0) {
                    bfs(newX, newY, grid);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int i, j;
        n = grid.size();
        m = grid[0].size();
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++)
                visited[i][j] = 0;
        }
        
        int islands = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    islands++;
                    bfs(i, j, grid);
                }
            }
        }
        
        return islands;
    }
};
