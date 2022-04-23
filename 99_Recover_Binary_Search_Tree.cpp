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
class Solution {
public:
    TreeNode *last;
    TreeNode *last2;
    TreeNode *last3;
    void util(TreeNode *root){
        if(!root) return;

        util(root->left);
        if(last->val>root->val && last2 == nullptr){
            //cout<<" in last2 : root : "<<root->val<<" , last : "<<last->val<<endl;
            last2 = last;
        }
        if(last2 && last->val>root->val){
            //cout<<" in last3 : root : "<<root->val<<" , last2 : "<<last2->val<<endl;
            last3 = root;
        }
        last = root;

        util(root->right);
    }
    void recoverTree(TreeNode* root) {
        last = new TreeNode(INT_MIN);
        last2 = nullptr;
        last3 = nullptr;
        util(root);
        swap(last2->val, last3->val);
        
    }
};