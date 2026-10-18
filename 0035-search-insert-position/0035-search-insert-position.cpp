class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { // t.c - 0(log n), s.c- 0(1)
        int n = nums.size();
        int start = 0; int end = n-1;

        while(start <= end){
         int mid = (start + (end -  start) / 2);

         if(target < nums[mid]){
            end = mid-1; // search in first half
         }
         else if(target > nums[mid]){ // search in second half
            start = mid+1;
         }
         else{
            return mid; // found the mid
         }

        }
        return start; // When the target is found, you return mid immediately. Otherwise, when the loop ends, start is exactly the position where the target belongs.
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna