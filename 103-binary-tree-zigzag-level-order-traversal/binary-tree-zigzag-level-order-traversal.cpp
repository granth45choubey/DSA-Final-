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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == nullptr) return {};

        q.push(root);
        bool lefttoright = true;

        while(!q.empty()){
            int levelsize = q.size();
            vector<int> temp(levelsize);
            int first = 0;
            int last = levelsize -1;

            while(levelsize--){
                TreeNode* curr = q.front();
                q.pop();
                if(lefttoright == true){
                    temp[first] = curr->val;
                    first++;
                }
                else{
                    temp[last] = curr->val;
                    last--;
                }
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
            res.push_back(temp);
            lefttoright = 1 - lefttoright;
        }
        return res;
    }
};