class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0;  // t.c = 0(n) s.c 0(1)
        int j = 1;

        while(j < n){
            if(nums[i] != nums[j]) {// found unique element
            i++;
             nums[i] = nums[j];
        }
        j++;
        }
        return i+1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna