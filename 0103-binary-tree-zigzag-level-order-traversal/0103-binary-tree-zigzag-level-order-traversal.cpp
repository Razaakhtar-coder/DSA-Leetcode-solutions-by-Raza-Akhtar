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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans; // t.c - 0(n), s.c = 0(n)(queue + ans)

        if (root == NULL)
            return ans;

            bool reverseLevel = false; // initially the zigzag reversal is false

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left != NULL)
                    q.push(node->left);

                if(node->right != NULL)
                q.push(node->right);
            }

            if(reverseLevel){
                reverse(level.begin(), level.end()); // zigzag condition
            }

            ans.push_back(level);
            reverseLevel = !reverseLevel; //Whatever the current value is, change it to the opposite.
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna