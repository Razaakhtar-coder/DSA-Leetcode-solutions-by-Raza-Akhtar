class Solution {
public:
     int dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == 0) 
          return 0;

          vis[i][j] = true;

         return 1 + dfs(i-1, j, n, m, grid, vis)
          + dfs(i, j+1, n, m, grid, vis)
          + dfs(i+1, j, n, m, grid, vis)
          + dfs(i, j-1, n, m, grid, vis);
     }



    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int maxArea = 0;
          for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j])
                maxArea = max(maxArea, dfs(i, j, n, m, grid, vis));
            }
          }
          return maxArea;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna