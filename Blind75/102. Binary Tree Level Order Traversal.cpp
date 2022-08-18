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
    vector<vector<int>> sol;
    queue<TreeNode*> q;
    void level(TreeNode* root) {
        if(q.empty()) {
            q.push(root);
        }
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> thislevel;
            for(int i = 0 ; i < size; i++) {
                TreeNode* nd = q.front();
                q.pop();
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
                thislevel.push_back(nd->val);
            }
            sol.push_back(thislevel);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root != NULL) level(root);
        return sol;
    }
};
