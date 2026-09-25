/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void fill(TreeNode* root, int sum, vector<int> temp, int& targetSum){
        if(!root){ // if root is NULL
            return;
        }

        sum += root->val; // add the sum if root is not NULL
        temp.push_back(root->val); // puh it in temp

        if(root->left == NULL && root->right == NULL){ // if we have reached to the leaf node from left, right
            if(sum == targetSum){ // and found the target
                ans.push_back(temp); // push it 
            }
            return;
        }
        fill(root->left, sum, temp, targetSum); // recursively check left
        fill(root->right, sum, temp, targetSum); // recursively check right

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;

        fill(root, sum, temp, targetSum);

       return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna