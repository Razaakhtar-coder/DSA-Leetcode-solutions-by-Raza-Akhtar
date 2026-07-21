class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool find(vector<vector<char>>& board, int i, int j, int idx, string &word) {
        if(idx == word.size())
            return true;

        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$')
            return false;

        if(board[i][j] != word[idx])
            return false;

        char temp = board[i][j];  // storing word in temp before marking it as visited
        board[i][j] = '$';

        for(auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(find(board, new_i, new_j, idx + 1, word))
                return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && find(board, i, j, 0, word)) //Time Complexity: O(m×n×4L), where L is the length of word.
//Space Complexity: O(L) due to the recursion stack.
                    return true;
            }
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna