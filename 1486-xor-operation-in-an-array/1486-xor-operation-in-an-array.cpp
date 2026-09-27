class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;

        for(int i=0; i<n; i++){
            ans =  ans ^ (start + 2 * i); // according to the condition given in question
        }
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna