class Solution {

private:
    // Do reverse inorder
    // process right then add sum to current root and update sum
    TreeNode *util(TreeNode *r, int &sum){
        if(!r) return r;

        util(r->right, sum);
        r->val = r->val + sum;
        sum = r->val;        
        util(r->left, sum);
        return r;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        return util(root, sum);
    }
};
