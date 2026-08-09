class Solution {
public:
int n, m;
   int dp[50][50][50];
   int maxCherry(vector<vector<int>>& grid, int r1, int c1, int r2, int c2){
     if(r1 >= n || r2 >= n || c1 >= m || c2 >= m || grid[r1][c1] == -1 || grid[r2][c2] == -1){
        return INT_MIN; // if we are out of bound
     }
     r1 = r2 + c2 - c1;
     if(dp[c1][r2][c2] != -1){ // already found a path
        return dp[c1][r2][c2]; 
     }
     int q1 = grid[r1][c1];
     int q2 = grid[r2][c2];
     int cherries = 0; // initialize the cherries as 0.
     if(r1 == r2 && c1 == c2){
        cherries += grid[r1][c1];
        if(r1 == n-1 && c1 == n-1){ // reached to the end
            dp[c1][r2][c2] = grid[r1][c1];
            return dp[c1][r2][c2];
        }
        grid[r1][c1] = 0;
     }
     else{
        cherries += grid[r1][c1] + grid[r2][c2];
        grid[r1][c1] = 0;
        grid[r2][c2] = 0;
     }
     int p1 = maxCherry(grid, r1, c1+1, r2, c2+1); // 1 0 1 0
     int p2 = maxCherry(grid, r1+1, c1, r2+1, c2); // 1 0 0 1
     int p3 = maxCherry(grid, r1, c1+1, r2+1, c2);
     int p4 = maxCherry(grid, r1+1, c1, r2, c2+1);
     grid[r1][c1] = q1;
     grid[r2][c2] = q2;

     dp[c1][r2][c2] = cherries + max(max(p1, p2), max(p3, p4));
     return dp[c1][r2][c2]; 

   }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));

        int r = maxCherry(grid, 0, 0, 0, 0);
        if(r <= 0)
        return 0;
        return r;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna