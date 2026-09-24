class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();

        int count = 0;
        int ans = 0;
        
        for(int i=0;i<n; i++){
            if(s[i] == 'R'){ // substr should start with R, given i question
            count++; // increase count.

            } else{
                count--; // or decrease count if letters are not equal in quantity
            }

            if(count == 0){
                ans++;
            }
        }
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
