class Solution {
public:
    int findNumbers(vector<int>& nums) { // TC: O(n × d), SC: O(1)
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int digit = 0;
        

        while(num > 0){ // count digit of that perticular number
            digit ++;
            num /= 10; // to remove the last digit of the number
        }

        if(digit % 2 == 0){ // if its even
            count ++;
        }
        }
        return count; // return count that we got  
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna