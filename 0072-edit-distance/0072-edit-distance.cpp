class Solution {
public:
     int m, n;
    int dp[501][501];

    int solve(string s1, string s2, int i, int j){
        if(i == s1.size())
        return n-j; // insert element if i becomes out of bound

        if(j == s2.size())
        return m-i; // delete element from s1 if j becomes out of bound

        if(s1[i] == s2[j]){
            return solve(s1, s2, i+1, j+1);
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int insert = 1 + solve(s1, s2, i, j+1);
        int delete1 = 1 + solve(s1, s2, i+1, j);
        int replace = 1 + solve(s1, s2, i+1, j+1);

        return dp[i][j] = min({insert, delete1, replace});
    
    }

    int minDistance(string s1, string s2) {
         m = s1.size();
         n = s2.size();
        memset(dp, -1, sizeof(dp));

        return solve(s1, s2, 0, 0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna