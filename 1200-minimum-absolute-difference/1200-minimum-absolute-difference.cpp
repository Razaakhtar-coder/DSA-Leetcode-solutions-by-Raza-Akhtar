class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

       vector<vector<int>>ans;

       int minDiff = INT_MAX; // finding min diffrence

       for(int i=1; i<arr.size(); i++){
         minDiff = min(minDiff, arr[i] - arr[i-1]);
       }
          for(int i=1; i<arr.size(); i++){ // storing all pairs of minimum difference
           if(arr[i] - arr[i-1] == minDiff){
               ans.push_back({arr[i-1], arr[i]}); // The curly braces {} create a list of values that we want to store together in one inner vector.
           }

          }
          return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna