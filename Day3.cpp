
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
class Solution {
private:
    int heightl(TreeNode* root){
        if(!root) return 0;
        return 1+heightl(root->left);
    }
    int heightr(TreeNode* root){
        if(!root) return 0;
        return 1+heightr(root->right);
    }
    int hiAyu(TreeNode* root){
        if(!root) return 0;
        int lh = heightl(root->left);
        int rh = heightr(root->right);
        if(lh == rh){
            return pow(2,lh+1)-1;
        }
        return hiAyu(root->left) + hiAyu(root->right) + 1;
    }
public:
    int countNodes(TreeNode* root) {
        return hiAyu(root);
    }
};

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
