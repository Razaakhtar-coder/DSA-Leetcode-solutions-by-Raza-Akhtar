class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
       int start = 0;
       int end = n-1;
       int position = n-1;

       while(start <= end){
        if(abs(nums[start]) > abs(nums[end])){
            ans[position--] = nums[start] * nums[start]; // decrease position after every squaring process

            start++;
        }
        else{
            ans[position--] = nums[end] * nums[end];  // decrease position after every squaring process
            end--;
        }
       }
       return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna