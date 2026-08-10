class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);

        dp[0] = false; // if n == 0(whoever takes turn looses it)

        for(int i=1; i<n+1; i++){
            for(int k=1; k*k<=i; k++){
                if(dp[i - (k*k)] == false){
                    dp[i] = true; // alice wins
                    break;
                }

            }
        }
        return dp[n];
    }
};

//T.C : O(n*sqrt(n))
//S.C : O(n)

// memoization code

// class Solution {
// public:
//     vector<int> t; //T.C : O(n * sqrt(n))
//     //S.C : O(n)

//     bool solve(int n) {

//         if(n == 0) {
//             return false;
//         }

//         if(t[n] != -1) {
//             return t[n] == 1 ? true : false;
//         }

//         for(int k = 1; k*k <= n; k++) { //O(sqrt(n))
            
//             if(solve(n - (k*k)) == false) {//Call for Bob //False - Bob lost it
//                 //Alice won the game
//                 return t[n] = true;
//             }

//         }

//         return t[n] = false; //Alice could never win. Lost it.

//     }

//     bool winnerSquareGame(int n) {
//         t.assign(n+1, -1);
//         return solve(n); //Alice k lie call hai ye. If it's true, Alice wins, else Alice looses
//     }
// };

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna