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
     int prevorder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return -1;
        }
        if(root->left != NULL){
            int leftans = kthSmallest(root->left, k); // left subtree
            if(leftans != -1){
                return leftans;     // t.c 0(n) and s.c 0(h)
            }
        }
         if(prevorder +1 == k){
            return root->val;
         }
         prevorder ++; // or it can be prevorder = prevorder + 1

         if(root->right != NULL){
            int rightans = kthSmallest(root->right, k); // right subtree
            if(rightans != -1){
                return rightans;
            }
         }
         return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna