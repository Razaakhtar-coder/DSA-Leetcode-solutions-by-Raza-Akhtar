class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        bool contains1 = false;
        for(int i=0; i<n; i++){
            if(nums[i] == 1) // if 1 is found in array
            contains1 = true;

            if(nums[i] <= 0 || nums[i] > n) // finding numbers only in range from [1, n]
               nums[i] = 1;
        }
        if(contains1 == false) // if one not present in array
          return 1;

          for(int i=0; i<n; i++){
            int num = abs(nums[i]); // take absolute value because we are taking -ve numbers to mark as visited
            int idx = num - 1;

            if(nums[idx] < 0) // if number already negative
            continue;

            nums[idx] *= -1; // if not , make it negative after visiting
          }

          for(int i=0; i<n; i++){
            if(nums[i] > 0)
            return i+1; // we never visited this idx so return this
          } 

          return n+1; // if we get every number we return n+1
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna