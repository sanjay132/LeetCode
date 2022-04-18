class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(!root) return -1;
        
        int l = kthSmallest(root->left, k);
        if(l!=-1) return l;
        k--;
        if(0==k)
            return root->val;
        int r = kthSmallest(root->right, k);
        return r;
    }
};