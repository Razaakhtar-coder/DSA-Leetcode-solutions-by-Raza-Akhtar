class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0]; // START WITH FIRST NUMBER

        for (int i = 1; i < nums.size(); i++) { // TRAVERSE FROM SECOND ELEMENT
            if (nums[i] == nums[i - 1] + 1) // NUBER IS EXACTLY GREATER THAN THE PREVIOUS NUMBER
                sum += nums[i];
            else
                break;
        }

        while (find(nums.begin(), nums.end(), sum) != nums.end()) { // FIND IF THE SUM ALREADY EXIST
            sum++;
        }

        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna