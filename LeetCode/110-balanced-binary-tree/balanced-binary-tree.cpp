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
    int maxDiff = 0;
public:
    int helper(TreeNode* node, int depth) {
        if (!node) return depth;

        int left = helper(node->left, depth + 1);
        int right = helper(node->right, depth + 1);

        maxDiff = max(maxDiff, abs(left - right));

        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        helper(root, 0);
        return maxDiff <= 1;
    }
};