class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowcase[9][9] = {0};
        int colcase[9][9] = {0};
        int gridcase[9][9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) { // time complexity = 0(1) and same space complexity also

                if (board[i][j] == '.')  // used '.' for empty cells
                    continue;

                int number = board[i][j] - '0';  // convert char to int ex '8' - '0' = 8, '5' - '0' = 5 etc
                int k = (i / 3) * 3 + (j / 3);

                if (rowcase[i][number - 1]++ ||
                    colcase[j][number - 1]++ ||
                    gridcase[k][number - 1]++)
                    return false;
            }
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna