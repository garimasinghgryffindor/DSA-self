// Morris Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> res;
        TreeNode * curr = root;
        
        while(curr) {
            if(curr->left == NULL) {
                res.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode * node = curr->left;
                // go to the rightmost node of the left subtree
                // 2 cases: either we found the same node again
                // or we are drawing the thread between the rightmost node of the left subtree and the root
                // for the first time
                while(node->right!=NULL && node->right!=curr) {
                    node = node->right;
                }
                
                if(node->right == NULL) {
                    // draw the thread
                    node->right = curr;
                    curr = curr->left;
                }
                else {
                    // coming back to the root
                    node->right = NULL;
                    res.push_back(curr->val);
                    // since have traversed the left subtree
                    // now we will be traversing the right subtree
                    curr = curr->right;
                }
            }
        }
        
        return res;
    }
};


