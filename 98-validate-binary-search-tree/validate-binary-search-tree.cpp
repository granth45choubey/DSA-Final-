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

    bool fun(TreeNode* root,vector<int> &res){
        if(root == nullptr) return true;

        fun(root->left, res);
        res.push_back(root->val);
        fun(root->right,res);

        for(int i =0; i< res.size()-1;i++){
            if(res[i]>= res[i+1]) return false;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        vector<int> res;
        return fun(root,res);
    }
};