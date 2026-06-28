/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    void fun(TreeNode* &root,TreeNode* &p,TreeNode* &q,TreeNode* &ans){
        if(root->val < p->val){
            fun(root->right,p,q,ans);
        }
        else if(root->val > q->val){
            fun(root->left,p,q,ans);
        }
        else ans = root;
        return;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;
        TreeNode* ans = nullptr;
        if(p->val < q->val)
        fun(root,p,q,ans);
        else fun(root,q,p,ans);
        return ans;
    }
};