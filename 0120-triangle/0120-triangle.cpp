class Solution {
public:
    int n;
    int dp[201][201];
    bool vis[201][201];

    int solve(vector<vector<int>>& triangle, int row, int col) {
        if (row == n - 1)
            return triangle[row][col];

        if (vis[row][col])
            return dp[row][col];

        vis[row][col] = true;

        int minPath = triangle[row][col] +
                      min(solve(triangle, row + 1, col),
                          solve(triangle, row + 1, col + 1));

        return dp[row][col] = minPath;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        memset(vis, 0, sizeof(vis));
        return solve(triangle, 0, 0);
    }
};

// bottom up code below

//T.C : O(n^2)
//S.C : O(n^2)
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> t = triangle;  // copy triangle for t

//         // Start from second last row and move upwards
//         for (int row = n - 2; row >= 0; row--) {
//             for (int col = 0; col <= row; col++) { //1st row me 1 column, 2nd Row me 2 Columns, and so on, that's why (col <= row)
//                 t[row][col] += min(t[row + 1][col], t[row + 1][col + 1]);
//             }
//         }

//         return t[0][0];  // minimum path sum
//     }
// };

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna