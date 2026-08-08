class Solution {
public:
    int n, m;
    int dp[71][71][71];

    int solve(vector<vector<int>>& grid, int row, int col1, int col2){
        if(row >= m)
        return 0;

        if(dp[row][col1][col2] != -1){
            return dp[row][col1][col2];
        }

        int cherry = grid[row][col1];
        if(col1 != col2){
        cherry += grid[row][col2];
        }

        int ans = 0;
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){

                int newRow = row + 1;
                int newCol1 = col1 + i;
                int newCol2 = col2 + j;

                if(newCol1 >= 0 && newCol1 < n && newCol2 >= 0 && newCol2 < n)
                 ans = max(ans, solve(grid, newRow, newCol1, newCol2));
            }
        }
        return dp[row][col1][col2] = ans + cherry;


    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return solve(grid, 0, 0, n-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna