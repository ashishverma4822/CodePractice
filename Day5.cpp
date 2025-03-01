
// Problem 1 : 105. Construct Binary Tree from Preorder and Inorder Traversal

class Solution {
private: 
    TreeNode* hiAyu(int s,int e,int &i,vector<int>& preorder){
        if(s>e or i>=preorder.size()) return nullptr;
        int idx = i;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = hiAyu(s,mp[preorder[idx]]-1,i,preorder);
        root->right = hiAyu(mp[preorder[idx]]+1,e,i,preorder);
        return root;
    }
public:
    unordered_map<int,int>mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        int i = 0;
        return hiAyu(0,preorder.size()-1,i,preorder);
    }
};

//Problem 2: 106. Construct Binary Tree from Inorder and Postorder Traversal

class Solution {
private: 
    TreeNode* hiAyu(int s,int e,int &i,vector<int>& preorder){
        if(s>e or i<0) return nullptr;
        int idx = i;
        TreeNode* root = new TreeNode(preorder[i--]);
        root->right = hiAyu(mp[preorder[idx]]+1,e,i,preorder);
        root->left = hiAyu(s,mp[preorder[idx]]-1,i,preorder);
        return root;
    }
public:
    unordered_map<int,int>mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0) return nullptr;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        int i = postorder.size()-1;
        return hiAyu(0,postorder.size()-1,i,postorder);
    }
};

// Problem 3 : 889. Construct Binary Tree from Preorder and Postorder Traversal

class Solution {
private:
    TreeNode* hiAyu(int prestart, int poststart, int preend, vector<int>&preorder, vector<int>& postorder){
        if(prestart>preend) return nullptr;
        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart == preend) return root;
        int next_node = preorder[prestart+1];
        int j = mp[next_node];
        int num = j-poststart+1;
        root->left = hiAyu(prestart+1,poststart,prestart+num,preorder,postorder);
        root->right = hiAyu(prestart+num+1,j+1,preend,preorder,postorder);
        return root;
    }
public:
    unordered_map<int,int>mp;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(postorder.size()==0) return nullptr;
        for(int i=0;i<postorder.size();i++) mp[postorder[i]] = i;
        int i = postorder.size() - 1;
        return hiAyu(0,0,preorder.size()-1,preorder,postorder);
    }
};
