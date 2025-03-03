
//Problem : 572. Subtree of Another Tree

class Solution {
private:  
    bool helpme(TreeNode* root1, TreeNode* root2){
        if(!root1 and !root2) return true;
        if(!root1 and root2) return false;
        if(root1 and !root2) return false;
        if(root1->val!=root2->val) return false;
        return helpme(root1->left,root2->left) and helpme(root1->right,root2->right);
    }
    bool hiAyu(TreeNode* root, TreeNode* subRoot){
        if(!root) return false;
        bool ans = helpme(root,subRoot);
        return ans or hiAyu(root->left,subRoot) or hiAyu(root->right,subRoot);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return hiAyu(root,subRoot);
    }
};
