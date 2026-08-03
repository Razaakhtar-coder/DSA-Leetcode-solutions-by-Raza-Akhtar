class Solution {
public:
     string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1); // initialize dp array

        for(int i=n-1; i>=0; i--){ // looping backword because we have to fill t[i+3]....t[i]
            dp[i] = stoneValue[i] - dp[i+1]; 

            if(i+2 <= n) 
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] - dp[i+2]); // return max score

            if(i+3 <= n)
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3]); // return max score
        }

        int difference = dp[0];

        if(difference > 0){ // if(alice - bob > 0) A->9 & b->4 means diff is +ve so return alice
            return "Alice";
        }
        else if(difference < 0){ // if(alice - bob < 0) A->4 & b->9 means diff is -ve so return bob
            return "Bob";
        }
        else{    // or tie
            return "Tie";
        }
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna