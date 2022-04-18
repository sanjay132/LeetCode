class Solution {
private:
    TreeNode *last;
    TreeNode *newRoot;
public:
    
    void util(TreeNode *root){
        if(!root) return ;
        
        util(root->left);
        if(!last){
            last = root;
            newRoot = last;
        }else{
            last->left = nullptr;
            last->right = root;
            last = root;
        }
        util(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        last = nullptr;
        util(root);
        last->left = nullptr;
        root = newRoot;
        return root;
    }
};