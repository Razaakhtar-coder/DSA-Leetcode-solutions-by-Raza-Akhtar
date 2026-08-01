class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;

        for(int i=0; i<n; i++){
           int count = 0;
            for(int j=i; j<n; j++){

                count += (nums[j] == target) ? +1:-1;
                if(count > 0){
                    result ++;
                }
            }
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna