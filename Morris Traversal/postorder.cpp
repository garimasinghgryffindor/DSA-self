
// MORRIS TRAVERAL
// ITERATIVE
// without recursion

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->right == NULL) {
                res.push_back(curr->val);
                curr = curr->left;
            } else {
                // 2 cases
                // we have either reached the node for the very first time
                // or we are traversing it again after coming from the thread that we drew
                TreeNode * node = curr->right;
                while(node->left!=NULL && node->left!=curr) {
                    node = node->left;
                }
                if(node->left == NULL) {
                    // we are traversing the root node for the first time
                    // therefore, draw the thread
                    node->left = curr;
                    res.push_back(curr->val);
                    curr = curr->right;
                } else {
                    // we have already traversed the root and it's right subtree as well
                    // therefore we reached here again inorder to traverse the left subtree
                    // so, remove the thread and traverse the left subtree
                    node->left = NULL;
                    curr = curr->left;
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


