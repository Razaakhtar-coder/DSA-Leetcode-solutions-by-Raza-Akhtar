class Solution {
public:
    int countPairs(vector<int>& nums, int target) { // t.c - 0(n*n), s.c - 0(1)
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] < target){
                    count++;
                }
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna