/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Approach takes O(N) space
// Time : O(1) time for hasNext and Next on Average
/*class BSTIterator {
private:
    int curr;
    vector<int> inorder;
    
    void doInorder(TreeNode *root){
        if(!root) return;
        doInorder(root->left);
        inorder.push_back(root->val);
        doInorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        doInorder(root);
        curr = 0;
    }
    
    int next() {
        return inorder[curr++];
    }
    
    bool hasNext() {
        return (curr<inorder.size());
    }
};
*/

// Avg Time : O(1)
// Avg Space: O(h), height of tree since we are using stack which only store the left nodes 
                    // which can go max size upto the height of tree
class BSTIterator {
private:
    stack<TreeNode *> st;
public:
    BSTIterator(TreeNode* root) {
        // Fill all the left nodes to the stack st
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode *node = st.top();
        st.pop();
        int data = node->val;
        if(node->right){
            node = node->right;
            while(node){
                st.push(node);
                node = node->left;
            }
        }
        return data;
    }
    
    bool hasNext() {
        return (st.size()>0);
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */