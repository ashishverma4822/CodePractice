
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
