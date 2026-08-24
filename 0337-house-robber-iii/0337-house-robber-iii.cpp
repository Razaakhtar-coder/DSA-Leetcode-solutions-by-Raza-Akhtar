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
    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        auto leftans = solve(root->left);
        auto rightans = solve(root->right);

        // If we rob this node, we cannot rob its children
        int robCurrent = root->val
                       + leftans.second
                       + rightans.second;

        // If we don't rob this node, choose the best option for each child
        int skipCurrent = max(leftans.first, leftans.second)
                        + max(rightans.first, rightans.second);

        return {robCurrent, skipCurrent};
    }

    int rob(TreeNode* root) {
        auto ans = solve(root);

        return max(ans.first, ans.second);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna