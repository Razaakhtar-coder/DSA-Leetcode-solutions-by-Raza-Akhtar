class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        // Find how many zeros can actually be duplicated
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0)
                zeros++;
        }

        int i = n - 1; // i → points to the original array
        int j = n + zeros - 1; // j → points to the conceptual expanded array

        // Work backwards
        while (i >= 0 && j >= 0) {
            if (j < n) // Only write if this position actually exists in the real array."
                arr[j] = arr[i]; // When we encounter zero, we've already copied one zero

            if (arr[i] == 0) { // original - 102
                j--;

                if (j < n) // expanded - 1002
                    arr[j] = 0; // write the duplicate zero
            }

            i--; // j-- is done two times because in j 0 are 2 - 00 so j-- twice
            j--;
        }
    }
};

// class Solution {
// public:
//     void duplicateZeros(vector<int>& arr) {
//         int i = 0; int temp = 0;
//         bool edgeZero = false;
        
//         while(temp < arr.size()){
//             if(arr[i] == 0){
//                 i++;
//             }
//             if(temp == arr.size()-1){
//                 edgeZero = true;
//                 temp++;
//             }
//             else{
//                 temp += 2;
//             }
//             else{
//                 i++; temp++; // if we do not encounter zeros
//             }
//         }
//         i--; temp--; // handling edge cases if only one zero at end
//         if(edgeZero ==  true){
//             arr[temp] = arr[i];
//             temp--; i--;
//         }
//         while(i >= 0){
//             if(arr[i] == 0){
//                 arr[temp] = 0;
//                 arr[temp-1] = 0;
//                 temp -= 2;
//                 i--;
//             }
//             else{
//                 arr[temp] = arr[i];
//                 i--; temp--;
//             }
//         }
//     }
// };

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna