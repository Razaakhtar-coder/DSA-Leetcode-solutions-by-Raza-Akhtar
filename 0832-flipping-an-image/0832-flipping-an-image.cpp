class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) { // TC: O(m*n), s.c: 0(1)
        int n = image.size();

        for(int i=0; i<n; i++){
            int left = 0;
            int right = n-1;

            while(left <= right){
                swap(image[i][left], image[i][right]);

                image[i][left] = 1 - image[i][left]; // flip the bits

                if(left != right){
                    image[i][right] = 1 - image[i][right]; // We must also flip the right element
                }
                left++; // Move the pointers inward
                right--;
            }
        }
        return image;
    }
};

// class Solution { // TC: O(m*n), s.c: 0(m*n)
// public:
//     vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
//         int m = image.size();
//         int n = image[0].size();

//         vector<vector<int>> ans(m, vector<int>(n));

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 ans[i][n - 1 - j] = 1 - image[i][j]; // n - 1 - j puts the element in the reversed position, 1 - image[i][j] flips the bit.
//             }
//         }

//         return ans;
//     }
// };

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna