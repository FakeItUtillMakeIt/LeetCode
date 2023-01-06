class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) {
            return ret;
        }

        queue <TreeNode*> q;
        q.push(root);
        vector<int> vv;
        while (!q.empty()) {
            
            //每次得到当前层的所有元素个数并输出
            int currentLevelSize = q.size();
            
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                
                vv.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if(!vv.empty())
                ret.push_back(vv);
            vv.clear();
        }
        
        return ret;
    }
};

