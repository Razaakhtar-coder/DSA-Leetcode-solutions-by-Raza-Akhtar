class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        
    int i = 0;
    int j = arr.size() - 1;
      while(i < j){

        if(arr[i] + arr[j] < target){
            i++;
        }
        else if(arr[i] + arr[j] > target){
            j--;
        }
        else{
            return{i+1, j+1};
        }

        }
        return {};
      }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna