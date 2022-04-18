class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {

        // Null Node
        if(!root) return root;

        if(root->val>=low && root->val<=high){
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }else if(root->val < low){
            return trimBST(root->right, low, high);
        }else
            return trimBST(root->left, low, high);
        
    }
};