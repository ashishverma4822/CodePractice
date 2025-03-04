
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


// Problem 2 :107. Binary Tree Level Order Traversal II

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
        reverse(uttar.begin(),uttar.end());
        return uttar;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        return hiAyu(root);
    }
};

// Problem 3 : 993. Cousins in Binary Tree

class Solution {
private: 
    void hiAyu(TreeNode* root,TreeNode* par,int x, int y, int level){
        if(!root) return;
        if(root->val == x){
            mp[root->val] = {par,level};
        }
        if(root->val == y){
            mp[root->val] = {par,level};
        }
        hiAyu(root->left,root,x,y,level+1);
        hiAyu(root->right,root,x,y,level+1);
    }
public:
    unordered_map<int,pair<TreeNode*,int>>mp;
    bool isCousins(TreeNode* root, int x, int y) {
        hiAyu(root,nullptr,x,y,0);
        if(mp[x].first==mp[y].first) return false;
        if(mp[x].second!=mp[y].second) return false;
        else return true;
    }
};
