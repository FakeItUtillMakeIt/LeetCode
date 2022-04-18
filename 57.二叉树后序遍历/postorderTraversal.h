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
    void postSortFun(TreeNode* root,vector<int>& postSort){
        if(root==nullptr){
            return ;
        }
        postSortFun(root->left,postSort);
        postSortFun(root->right,postSort);
        postSort.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postSort;
        
        postSortFun(root,postSort);
        return postSort;
    }
};