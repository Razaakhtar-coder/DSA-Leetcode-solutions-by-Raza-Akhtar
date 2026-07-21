class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {-1, 0}));
        dp[n-1][n-1] = {0, 1};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;

                vector<pair<int,int>> prev;

                if (i + 1 < n && dp[i + 1][j].first != -1) //up
                    prev.push_back(dp[i + 1][j]);

                if (j + 1 < n && dp[i][j + 1].first != -1) // left
                    prev.push_back(dp[i][j + 1]);

                if (i + 1 < n && j + 1 < n && dp[i + 1][j + 1].first != -1) // diagonal left
                    prev.push_back(dp[i + 1][j + 1]);

                if (prev.empty()) continue;

                int mx = -1, ways = 0;

                for (auto &p : prev) {
                    if (p.first > mx) { //Found larger score.
                        mx = p.first; //Update maximum.
                        ways = p.second; //Current ways become
                    } else if (p.first == mx) { //Another neighbour gives same maximum score.
                        ways = (ways + p.second) % MOD; //ways = (ways + p.second) % MOD;
                    }
                }

                int val = 0;  // cell value
                if (board[i][j] >= '0' && board[i][j] <= '9')  // if cell contains 1, 2, ..., 9 
                    val = board[i][j] - '0'; // convert character to integer

                dp[i][j] = {mx + val, ways};
            }
        }

        if (dp[0][0].first == -1)
            return {0, 0};

        return {dp[0][0].first, dp[0][0].second};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna