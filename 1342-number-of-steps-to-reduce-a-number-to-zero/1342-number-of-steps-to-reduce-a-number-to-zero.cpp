class Solution {
public:
    int numberOfSteps(int num) { // t.c - 0(logn) -> Dividing repeatedly by 2 takes about log₂(n) steps. s.c - 0(1)
        int stepCount = 0;

        while(num > 0){
            if(num % 2 == 0){ // even number
              num = num/2;
              stepCount ++;
            }
            else{
                num = num - 1; // if number is odd
                stepCount ++;
            }
        }
        return stepCount;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna