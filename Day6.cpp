
// Problem 1 : Same Tree
class Solution {
private: 
    bool hiAyu(TreeNode* p, TreeNode* q){
        if(!p and !q) return true;
        if(p and !q) return false;
        if(!p and q) return false;
        if(p->val != q->val) return false;
        else return hiAyu(p->left,q->left) and hiAyu(p->right,q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return hiAyu(p,q);
    }
};

//Problem 2 : Two Mirror Trees
class Solution {
  private:
    bool hiAyu(Node* a, Node* b){
        if(!a and !b) return true;
        if(!a and b) return false;
        if(a and !b) return false;
        if(a->data != b->data) return false;
        return hiAyu(a->left,b->right) and hiAyu(a->right,b->left);
    }
  public:
    int areMirror(Node* a, Node* b) {
        // Your code here
        return hiAyu(a,b);
    }
};

// Problem 3 : 617. Merge Two Binary Trees
class Solution {
private:
    TreeNode* hiAyu(TreeNode* root1, TreeNode* root2){
        if(!root1 and !root2) return nullptr;
        if(!root1 and root2) return root2;
        if(root1 and !root2) return root1;
        root1->val = root1->val + root2->val;
        root1->left = hiAyu(root1->left,root2->left);
        root1->right = hiAyu(root1->right,root2->right);
        return root1;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return hiAyu(root1,root2);
    }
};
