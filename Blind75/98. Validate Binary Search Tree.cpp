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
// public:
//     bool isValid(TreeNode* root, int left, int right) {
//         if (not root) return true;
//         if (not (root->val > left and root->val < right)) {
//             return false;
//         }
//         return isValid(root->left, left, root->val) and isValid(root->right, root->val, right);
//     }
//     bool isValidBST(TreeNode* root) {
//         if (not root->left and not root->right) return true;
//         return isValid(root, INT_MIN, INT_MAX);
//     }
    
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return inorder(root, prev);
    }
private:
    bool inorder(TreeNode* root, TreeNode*& prev) {
        if (root == NULL) {
            return true;
        }
        
        if (!inorder(root->left, prev)) {
            return false;
        }
        
        if (prev != NULL && prev->val >= root->val) {
            return false;
        }
        prev = root;
        
        if (!inorder(root->right, prev)) {
            return false;
        }
        
        return true;
    }
};
