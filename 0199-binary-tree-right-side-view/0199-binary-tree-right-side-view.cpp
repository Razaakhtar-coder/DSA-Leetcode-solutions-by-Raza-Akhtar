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
    void preOrder(TreeNode* root, int level, vector<int>& ans) {
        if(root == NULL) return;

        if(ans.size() < level){
            ans.push_back(root->val);
        }

        preOrder(root->right, level+1, ans);
        preOrder(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root){
        vector<int> ans;

        preOrder(root, 1, ans);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna