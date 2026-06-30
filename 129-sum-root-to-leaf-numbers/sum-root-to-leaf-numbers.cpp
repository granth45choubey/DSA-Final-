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

    int fun(TreeNode* root, int sum){
        if(root == nullptr) return 0;
        sum = sum*10 + root->val;
        if(root->left == nullptr && root->right == nullptr) return sum; 

        return fun(root->left,sum) + fun(root->right,sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return fun(root,sum);
        

         }
};