class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for(int i=1; i<=n; i++){
        if(i % 3 == 0 && i % 5 == 0){
            ans.push_back("FizzBuzz"); // if n is div by 3 & 5
        }
        else if(i % 3 == 0){ // if n is div by only 3
           ans.push_back("Fizz");
        }
        else if(i % 5 == 0){ // if n is div by only 5
            ans.push_back("Buzz");
        }
        else{
            ans.push_back(to_string(i)); // or else return this if there is no answer from the above conditions
        }
        }

        return ans;
              

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna