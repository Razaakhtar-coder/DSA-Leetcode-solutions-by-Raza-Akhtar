class Solution {
public:
    int countOdds(int low, int high) { // TC: O(high - low + 1), SC: O(1)
       int count = 0;

       for(int i=low; i<=high; i++){
        if(i % 2 != 0){ // if not even
            count ++;
        }
       }
       return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna