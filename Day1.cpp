// Day 1 23/02/2025 -> Binary_Tree

// Preorder Traversal
//Problem 1

class Solution {
private:
    void hiAyu(TreeNode* root,vector<int>&preOrder){
        if(root==nullptr) return ;
        preOrder.push_back(root->val);
        hiAyu(root->left,preOrder);
        hiAyu(root->right,preOrder);
    }
    vector<int> hiAyu(TreeNode* root){
        if(!root) return {};
        vector<int>preOrder;
        preOrder.push_back(root->val);
        vector<int> left = hiAyu(root->left);
        preOrder.insert(preOrder.end(),left.begin(),left.end());
        vector<int> right = hiAyu(root->right);
        preOrder.insert(preOrder.end(),right.begin(),right.end());
        return preOrder;
    }
    vector<int>hiAyu2(TreeNode* root){
        if(!root) return {};
        vector<int>preOrder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* f = st.top();
            st.pop();
            preOrder.push_back(f->val);
            if(f->right) st.push(f->right);
            if(f->left) st.push(f->left);
        }
        return preOrder;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int>preOrder;
        // hiAyu(root,preOrder);
        // return preOrder;
        return hiAyu(root);
        // return hiAyu2(root);
    }
};

// Problem 2
class Solution {
private:
    void hiAyu(TreeNode* root,vector<int>&inOrder){
        if(root==nullptr) return ;
        hiAyu(root->left,inOrder);
        inOrder.push_back(root->val);
        hiAyu(root->right,inOrder);
    }
    vector<int> hiAyu(TreeNode* root){
        if(!root) return {};
        vector<int>inOrder;
        vector<int> left = hiAyu(root->left);
        inOrder.insert(inOrder.end(),left.begin(),left.end());
        inOrder.push_back(root->val);
        vector<int> right = hiAyu(root->right);
        inOrder.insert(inOrder.end(),right.begin(),right.end());
        return inOrder;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int>inOrder;
        // hiAyu(root,inOrder);
        // return inOrder;
        return hiAyu(root);
    }
};

//Problem 3
class Solution {
private:
    void hiAyu(TreeNode* root,vector<int>&postOrder){
        if(root==nullptr) return ;
        hiAyu(root->left,postOrder);
        hiAyu(root->right,postOrder);
        postOrder.push_back(root->val);
    }
    vector<int> hiAyu(TreeNode* root){
        if(!root) return {};
        vector<int>postOrder;
        vector<int> left = hiAyu(root->left);
        postOrder.insert(postOrder.end(),left.begin(),left.end());
        vector<int> right = hiAyu(root->right);
        postOrder.insert(postOrder.end(),right.begin(),right.end());
        postOrder.push_back(root->val);
        return postOrder;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int>postOrder;
        // hiAyu(root,postOrder);
        // return postOrder;
        return hiAyu(root);
    }
};

