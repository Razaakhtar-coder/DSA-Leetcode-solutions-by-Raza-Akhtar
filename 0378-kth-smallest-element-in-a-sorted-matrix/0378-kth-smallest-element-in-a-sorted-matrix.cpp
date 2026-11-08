class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) { // t.c - 0(logn), s.c - 0(1)
        int n = matrix.size();

        int start = matrix[0][0];
        int end = matrix[n-1][n-1];

        while(start < end){
          int mid = (start + (end - start) / 2);

          int count = 0; // Count elements using two pointers
          //count element <= mid
          int row = n-1;
          int col = 0;

          while(row >= 0 && col < n){
             if(matrix[row][col] <= mid) { // if the element is less than or equal to mid
                    count += row + 1; // increase count
                    col++; // increment col
                }
                else {
                    row--;
                }
          }
           if(count < k) { // decides in which direction we have to search
                start = mid + 1; // start moves
            }
            else {
                end = mid; // else end is mid
            }
        }
        return start;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna