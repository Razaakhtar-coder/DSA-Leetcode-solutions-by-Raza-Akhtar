class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int resultXor = 0;
        bool allZeros = true;

        for(auto &num : nums){
            resultXor = resultXor ^ num;

            if(num != 0){ // atleast one element found which is not zero
            allZeros = false;

            }

        }
        if(allZeros){ // we cannot take any subsequence
            return 0;
        }
        return resultXor == 0 ? n-1 : n; // if resultXor = 0 than take n-1 length or if its not 0 than take n length of array.
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna