class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(); // t.c- 0(n*n), s.c- 0(1).
        int count = 0;

        for (int i = 0; i < n; i++) {// take 2 loops
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) { // satisfy condition given in question
                    count++; // increase count
                }
            }
        }

        return count;
    }
};