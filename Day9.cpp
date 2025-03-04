
// Problem 1 : 102. Binary Tree Level Order Traversal

class Solution {
private:
    vector<vector<int>> hiAyu(TreeNode* root){
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>> uttar;
        vector<int> v;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto f = q.front();
                q.pop();
                if(f) v.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            uttar.push_back(v);
            v.clear();
        }
        return uttar;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return hiAyu(root);
    }
};
