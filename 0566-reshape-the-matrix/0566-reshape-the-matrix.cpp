class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& matrix, int r, int c) { // TC: 0(m*n) and same space complexity
        int m = matrix.size();
        int n = matrix[0].size();

        if(m*n != r*c){ // check whether reshaping is possible.
            return matrix;
        }
         vector<vector<int>> ans(r, vector<int>(c)); // This creates a matrix with r rows and c columns.

         int row = 0;
         int col = 0;

         for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[row][col] = matrix[i][j]; // We read elements from the original matrix and put them into the new matrix.

                col++;
                if(col == c){ // When a row is full, reset the column to 0 and move to the next row.
                    col = 0;
                    row++;
                }
            }
         }
         return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna