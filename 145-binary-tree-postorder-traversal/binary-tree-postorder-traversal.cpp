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

    void fun(TreeNode*TreeNode,vector<int> &ans){
        if(TreeNode == nullptr) return;

        fun(TreeNode -> left,ans);
        fun(TreeNode -> right,ans);
        ans.push_back(TreeNode -> val);
        return;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        fun(root,ans);
        return ans;
    }
};