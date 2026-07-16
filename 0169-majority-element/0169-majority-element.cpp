class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;

        for(int i=0; i<nums.size(); i++){
            if(freq == 0){
                ans = nums[i];
            }
        
        if(ans == nums[i]){
            freq ++;
        }
        else{
            freq --;
        }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna