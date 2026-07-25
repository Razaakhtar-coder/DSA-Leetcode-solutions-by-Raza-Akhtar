class Solution {
public:
      int fib(int n){ // t.c -> 0(n) s.c -> 0(1)
        if(n <= 1)
        return n;

        int c;
        int a = 0, b = 1;

        for(int i=1; i<n; i++){
            c = a + b;
            a = b;
            b = c;
        }

        return c;
      }
};  
     //recursion + memoized solution below

    //  int solve(int n, vector<int>& dp){
    //     if( n <= 1)
    //     return n;

    //     if(dp[n] != -1)
    //     return dp[n];

    //     return solve(n-1, dp) + solve(n-2, dp);
    //  }

    // int fib(int n) {
    //     if( n <= 1)
    //     return n;

    //     vector<int> dp(n+1, -1);
    //     return solve(n, dp);


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
