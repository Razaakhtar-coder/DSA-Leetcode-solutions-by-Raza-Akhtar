class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) { // t.c- 0(m*n), s.c- 0(m*n)
        int m = matrix.size(); // defining column
        int n = matrix[0].size(); // defining column

        vector<vector<int>> ans(n, vector<int>(m));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[j][i] = matrix[i][j]; // changes the position of elements of rows and column
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna