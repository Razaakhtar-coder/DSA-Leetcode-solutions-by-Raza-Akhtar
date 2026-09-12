class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int countStr = 0;

        for(int i=0; i<operations.size(); i++){
            if(operations[i] == "++X" || operations[i] == "X++"){ // if we found X++ or ++X increase the counter
            countStr ++;
            }
            else{
                countStr --; // else decrease the counter
            }
        }
        return countStr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna