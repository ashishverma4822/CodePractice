
// Problem 1 : Check Completeness of a Binary Tree

class Solution {
private:
    bool hiAyu(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto f = q.front();
                q.pop();
                if(f==nullptr){
                    flag = true;
                }
                else{
                    if(flag==true) return false;
                    if(f->left) q.push(f->left);
                    else q.push(nullptr);
                    if(f->right) q.push(f->right);
                    else q.push(nullptr);
                }
            }
        }
        return true;
    }
public:
    bool isCompleteTree(TreeNode* root) {
        return hiAyu(root);
    }
};

// Problem 2 : Construct Binary Tree from Parent Array


class Solution {
  private:  
    void hiAyu(Node* root, unordered_map<int,vector<int>>&mp){
        if(!root) return ;
        if(mp.find(root->data)==mp.end()) return;
        int val = root->data;
        vector<int> v = mp[val];
        if(v.size()>0){
            root->left = new Node(v[0]);
            hiAyu(root->left,mp);
        }
        if(v.size()>1){
            root->right = new Node(v[1]);
            hiAyu(root->right,mp);
        }
    }
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
        unordered_map<int,vector<int>>mp;
        int k = 0;
        for(auto i: parent){
            mp[i].push_back(k);
            k++;
        }
        if(mp.size()==0) return nullptr;
        vector<int> v = mp[-1];
        Node * root = new Node(v[0]);
        hiAyu(root,mp);
        return root;
    }
};

// Problem 3 : Linked List to Binary Tree

class Solution {
  private:
    TreeNode* hiAyu(TreeNode* root, Node* head){
        if(!head) return root;
        queue<TreeNode*>q;
        q.push(root);
        while(head){
            TreeNode* f = q.front();
            q.pop();
            if(head){
                f->left = new TreeNode(head->data);
                q.push(f->left);
                head = head->next;
            }
            else f->left = nullptr;
            if(head){
                f->right = new TreeNode(head->data);
                q.push(f->right);
                head = head->next;
            }
            else f->right = nullptr;
        }
        return root;
    }
  public:
    TreeNode* linkedListToBinaryTree(Node* head) {
        // code here
        if(!head) return nullptr;
        TreeNode* root = new TreeNode(head->data);
        return hiAyu(root,head->next);
    }
};
