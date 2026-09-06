class Solution {
public:
    int getNext(int n){
        int sum = 0;
        while(n > 0){
            int digit = n % 10; //This gets the last digit of the number. ex- 19 % 10 = 9
            sum += digit * digit;
            n /= 10; // removes the last digit. ex- 19 / 10 = 1
        }
        return sum;
    }

    bool isHappy(int n) {

        int slow = n;
        int fast = getNext(n);

      while(fast != 1 && slow != fast){

        slow = getNext(slow);
        fast =  getNext(getNext(fast));
      }

        return fast == 1;

        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna