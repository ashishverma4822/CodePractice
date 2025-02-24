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
