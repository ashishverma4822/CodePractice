
//Problem : onstruct Binary Tree from String with bracket representation

class Solution{
private:
    int helpme(string &s, int &i) {
        int val = 0;
        while (i < s.size() && isdigit(s[i])) {
            val = val * 10 + (s[i] - '0');
            i++;
        }
        return val;
    }

    Node* hiAyu(string &str, int &i) {
        if (i >= str.size()) return nullptr;
        int val = helpme(str, i);
        Node* root;
        if(val!=0) root = new Node(val);
        else return nullptr;
        if (i < str.size() && str[i] == '(') {
            i++;
            root->left = hiAyu(str, i);
            i++;
        }
        if (i < str.size() && str[i] == '(') {
            i++;
            root->right = hiAyu(str, i);
            i++;
        }
        return root;
    }
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        int i = 0;
        return hiAyu(str,i);
    }
};
