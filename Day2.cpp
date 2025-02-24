// Problem 1 : Remove Half Nodes
class Solution {
  private:
    Node* hiAyu(Node* root){
        if (!root) return nullptr;
        root->left = hiAyu(root->left);
        root->right = hiAyu(root->right);
        if (!root->left and root->right) return root->right;
        if (root->left and !root->right) return root->left;
        return root; 
    }
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
        return hiAyu(root);
        
    }
};

// Problem 2 : Balanced Binary Tree
class Solution {
private:
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        int l = 1 + height(root->left);
        int r = 1 + height(root->right);
        return max(l,r); 
    }
    bool hiAyu(TreeNode* root){
        if(!root) return true; 
        int l = height(root->left);
        int r = height(root->right);
        bool hoKiNahi = abs(l-r) > 1 ? false : true;
        bool ls = hiAyu(root->left);
        bool rs = hiAyu(root->right);
        return hoKiNahi and ls and rs;
    }
    int hiAyu2(TreeNode* root){
        if(!root) return 0;
        int l = 1+hiAyu2(root->left);
        int r = 1+hiAyu2(root->right);
        haiKiNahi = haiKiNahi and (abs(l-r)>1 ? false : true);
        return max(l,r);
    }
public:
    bool haiKiNahi = true;
    bool isBalanced(TreeNode* root) {
        // return hiAyu(root);
        haiKiNahi = true;
        hiAyu2(root);
        return haiKiNahi;
    }
};
