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

    void fun(TreeNode* root, int k ,vector<int> &ans){
        if(root == nullptr) return;
        fun(root->left,k,ans);
        ans.push_back(root->val);
        fun(root->right,k,ans);
        return;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        if(root == nullptr) return false;
        fun(root,k,ans);
        int n = ans.size();
        int low = 0;
        int high = n - 1;

        while(low < high){
            if(ans[low] + ans[high] == k){ 
                return true;
                
            }
            else if(ans[low] + ans[high] < k) low++;
            else high--;
        }
        return false;
    }
};