class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) { // t.c - 0(log n), s.c - 0(1)
        int n = letters.size();
        int start = 0;
        int end = n - 1;

        while(start <= end){
            int mid = (start + (end - start) / 2);

            if(target < letters[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return letters[start % n]; // since the loop is running until 'start <= end', so at the end of the while loop, 'start === end+1'
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna