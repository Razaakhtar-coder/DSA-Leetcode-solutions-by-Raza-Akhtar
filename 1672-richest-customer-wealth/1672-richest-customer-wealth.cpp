class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;

        for(int i=0; i<accounts.size(); i++){

            int wealth = 0; //We reset the customer's wealth to zero.
        

        for(int j=0; j<accounts[i].size(); j++){ // This goes through each bank of the current customer.

            wealth += accounts[i][j]; // add the money
        }

            maxWealth = max(maxWealth, wealth); // return max of wealth
        
        }

        return maxWealth;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna