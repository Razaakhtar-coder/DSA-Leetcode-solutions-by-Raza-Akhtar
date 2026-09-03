class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        int closest = 100000; // assume it

        sort(nums.begin(), nums.end());

        for(int k=0; k<=n-3; k++){ // k is going to n-3 because we want only 3 elements to sum up the closest value
          int i = k+1;
          int j = n-1;

          while(i < j){
            int sum = nums[k] + nums[i] + nums[j];
            if(abs(target - sum) < abs(target - closest))
            closest = sum; // update closest if we got the new closest value

            if(sum < target)
              i++;
              else{
                j--;
              }
          }

        }
        return closest;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna