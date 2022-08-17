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
    int getHeight(TreeNode* root, int cnt) {
        if (root == NULL) return 0;
        cnt++;
        // cout << root->val <<" " << cnt << "\n";
        return max({getHeight(root->left, cnt), getHeight(root->right, cnt), cnt});
    }
    int maxDepth(TreeNode* root) {
        int cnt = 0;
        cnt = getHeight(root, cnt);
        return cnt;
    }
};
