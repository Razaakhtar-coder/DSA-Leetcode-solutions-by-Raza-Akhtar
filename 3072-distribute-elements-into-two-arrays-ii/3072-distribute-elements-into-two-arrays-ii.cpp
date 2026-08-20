class Solution {
public:

    // use Fenwick Tree to solve this problem
    class BIT {
    public:
        vector<int> tree;

        BIT(int n) {
            tree.resize(n + 1, 0);
        }

        void update(int index) {
            while (index < tree.size()) {
                tree[index]++;
                index += index & -index;
            }
        }

        int query(int index) {
            int sum = 0;

            while (index > 0) {
                sum += tree[index];
                index -= index & -index;
            }

            return sum;
        }
    };

    vector<int> resultArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        // Coordinate compression
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        sorted.erase(
            unique(sorted.begin(), sorted.end()),
            sorted.end()
        );

        BIT bit1(sorted.size());
        BIT bit2(sorted.size());

        // Get position/rank of nums[0] and nums[1]
        int rank1 = lower_bound(
            sorted.begin(),
            sorted.end(),
            nums[0]
        ) - sorted.begin() + 1;

        int rank2 = lower_bound(
            sorted.begin(),
            sorted.end(),
            nums[1]
        ) - sorted.begin() + 1;

        bit1.update(rank1);
        bit2.update(rank2);

        for (int i = 2; i < n; i++) {

            // Rank of current number
            int rank = lower_bound(
                sorted.begin(),
                sorted.end(),
                nums[i]
            ) - sorted.begin() + 1;

            // Number of elements <= nums[i]
            int lessEqual1 = bit1.query(rank);
            int lessEqual2 = bit2.query(rank);

            // Number of elements > nums[i]
            int greater1 = arr1.size() - lessEqual1;
            int greater2 = arr2.size() - lessEqual2;

            // Same decision logic as your original code
            if (greater1 > greater2) {

                arr1.push_back(nums[i]);
                bit1.update(rank);

            }
            else if (greater2 > greater1) {

                arr2.push_back(nums[i]);
                bit2.update(rank);

            }
            else if (arr1.size() <= arr2.size()) {

                arr1.push_back(nums[i]);
                bit1.update(rank);

            }
            else {

                arr2.push_back(nums[i]);
                bit2.update(rank);
            }
        }

        vector<int> ans = arr1;

        ans.insert(
            ans.end(),
            arr2.begin(),
            arr2.end()
        );

        return ans;
    }
};
// CODE IS CORRCT AND WORKING BUT GIVES TLE ON LEETCODE
// class Solution {
// public:
//     vector<int> resultArray(vector<int>& nums) { // t.c -> 0(n*n) and s.c-> 0(n)
//         vector<int> arr1;
//         vector<int> arr2;

//         arr1.push_back(nums[0]);
//         arr2.push_back(nums[1]);

//         for(int i=2; i<nums.size(); i++){
//             int greater1 = 0;
//             int greater2 = 0;

//         for(auto number : arr1){ // if the number is greater than nums[i] in arr1. example if the nums=5 ans arr= 3,4,6,7 so the 6 and 7 are greater than 5 so greater1 = 2 after greater1++
//             if(number > nums[i]){
//                 greater1++;
//             }
//         }

//         for(auto number : arr2){ // if the number is greater than nums[i] in arr2. example if the nums=5 ans arr= 3,4,6,7 so the 6 and 7 are greater than 5 so greater2 = 2 after greater2++
//             if(number > nums[i]){
//                 greater2++;
//             }
//         }
        

//         if(greater1 > greater2){
//             arr1.push_back(nums[i]);
//         }
//         else if(greater2 > greater1){
//             arr2.push_back(nums[i]);
//         }
//         else if(arr1.size() <= arr2.size()){ // If equal, put it in the smaller array. If still equal, put it in arr1.
//             arr1.push_back(nums[i]);
//         }
//         else{
//             arr2.push_back(nums[i]);
//         }
//         }

//         vector<int> ans = arr1;
//         ans.insert(ans.end(), arr2.begin(), arr2.end());

//         return ans;

//     }
// };

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna