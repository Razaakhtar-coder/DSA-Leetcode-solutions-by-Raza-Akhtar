class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int i = 0;
       int j = 0;
       int sum = 0;
       int maxSum = INT_MIN;

       while(j < nums.size()){
        sum += nums[j];

        if(j-i+1 == k){
            maxSum = max(maxSum, sum);

        sum -= nums[i];
        i++;
       }
       j++;
       }

       return (double)maxSum/k; // double for fetching the decimal part.
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna