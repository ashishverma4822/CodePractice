
//Problem 1 : 572. Subtree of Another Tree

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

// Problem 2 : Isomorphic Trees

class Solution {
  private:
    bool hiAyu(Node* root1, Node* root2){
        if(!root1 and !root2) return true;
        if(!root1 and root2) return false;
        if(root1 and !root2) return false;
        if(root1->data!=root2->data) return false;
        bool f1 = hiAyu(root1->left,root2->right) and hiAyu(root1->right,root2->left);
        bool f2 = hiAyu(root1->left,root2->left) and hiAyu(root1->right,root2->right);
        return f1 or f2;
    }
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1, Node *root2) {
        // add code here
        return hiAyu(root1,root2);
    }
};

// Problem 3 : 872. Leaf-Similar Trees

class Solution {
private:
    void hiAyu(TreeNode* root, vector<int>& v){
        if(!root) return;
        if(!root->left and !root->right){
            v.push_back(root->val);
            return;
        }
        hiAyu(root->left,v);
        hiAyu(root->right,v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1,r2;
        hiAyu(root1,r1);
        hiAyu(root2,r2);
        return r1==r2;
    }
};
