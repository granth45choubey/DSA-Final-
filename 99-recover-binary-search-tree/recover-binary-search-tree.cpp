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

    void inorder(TreeNode* root,vector<int> &res){
        if(root == nullptr) return;

        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }

    void fix(TreeNode* root, int &x, int &y){
        if(root == nullptr) return;

        if(root->val == x) root->val = y;
        else if(root->val == y) root->val =x;

        fix(root->left,x,y);
        fix(root->right,x,y);
    }

    void recoverTree(TreeNode* root) {
        vector<int> res;
        inorder(root,res);

        int galat = 0;
        int g1first,g1second,g2first,g2second;
        for(int i=0;i< res.size()-1; i++){
            if(res[i] >= res[i+1]){
                if(galat == 0){
                    g1first = res[i];
                    g1second = res[i+1];
                    galat++;
                }
                else{
                    g2first = res[i];
                    g2second = res[i+1];
                    galat++;
                }
            }
        }
        int x, y;
        if(galat == 1){
            x = g1first;
            y = g1second;
        }
        else{
            x = g1first;
            y = g2second;
        }
        fix(root,x,y);

        
    }
};