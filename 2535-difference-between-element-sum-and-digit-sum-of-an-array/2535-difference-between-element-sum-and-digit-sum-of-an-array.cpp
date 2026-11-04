class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();

        int elementSum = 0;
        int digitSum = 0;

        for(int num : nums){
          elementSum += num;
        
        while(num > 0){
            digitSum += num % 10;
            num /= 10;
        }
        }
        return abs(elementSum - digitSum);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna