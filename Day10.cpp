
// Problem 1 : 637. Average of Levels in Binary Tree

class Solution {
private:
    vector<double> hiAyu(TreeNode* root){
        if(!root) return {};
        queue<TreeNode*>q;
        vector<double> v;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int s = q.size();
            long long sum = 0;
            while(size--){
                auto f = q.front();
                q.pop();
                if(f) sum+=f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            v.push_back(double(sum)/s);
        }
        return v;
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        return hiAyu(root);
    }
};
