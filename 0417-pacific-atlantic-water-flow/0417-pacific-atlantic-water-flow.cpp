class Solution {
public:
    int m, n;
    
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        vis[r][c] = true;
        
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        
        for(auto &d : dirs) {
            int nr = r + d.first;
            int nc = c + d.second;
            
            if(nr>=0 && nc>=0 && nr<m && nc<n &&
               !vis[nr][nc] &&
               heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, vis);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // Pacific (top row + left column)
        for(int i=0;i<m;i++) dfs(i, 0, heights, pacific);
        for(int j=0;j<n;j++) dfs(0, j, heights, pacific);
        
        // Atlantic (bottom row + right column)
        for(int i=0;i<m;i++) dfs(i, n-1, heights, atlantic);
        for(int j=0;j<n;j++) dfs(m-1, j, heights, atlantic);
        
        vector<vector<int>> result;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i,j});
                }
            }
        }
        
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna