
// Problem 1 : Diameter of Binary Tree

class Solution {
private:
    int hiAyu(TreeNode* root){
        if(!root) return 0;
        int l = hiAyu(root->left);
        int r = hiAyu(root->right);
        uttar = max(uttar, l+r);
        return 1+max(l,r);
    }
public:
    int uttar;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        hiAyu(root);
        return uttar;
    }
};

// Problem 2 : Count Complete Tree Node


//Problem 3 : Minimum Depth of Bnary Tree
class Solution {
private:    
    int hiAyu(TreeNode* root){
        if(!root) return 0;
        if(!root->left and !root->right) return 1;
        int l = 1e5, r = 1e5;
        if(root->left) l = hiAyu(root->left);
        if(root->right) r = hiAyu(root->right);
        return 1+min(l,r);
    }
public:
    int minDepth(TreeNode* root) {
        return hiAyu(root);
    }
};
