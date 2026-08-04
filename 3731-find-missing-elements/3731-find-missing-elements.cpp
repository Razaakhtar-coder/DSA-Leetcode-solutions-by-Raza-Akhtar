class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;

        int smallest = nums[0]; // initially we assume that both smallest and largest number is first element
        int largest = nums[0];

        for(auto x: nums){ // x -> num.
        if(x < smallest) // find the smallest number of array
          smallest = x;

          if(x > largest) // find largest number of th array
          largest = x;
        }

          unordered_set<int> s; // put x means num in set
          for(auto x: nums){
            s.insert(x);
          }

          for(int i=smallest+1; i<largest; i++){ // find missing number between smallest and largest
            if(s.find(i) == s.end()){
                ans.push_back(i);
            }
          }
             return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna