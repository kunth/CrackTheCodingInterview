//Same with Leetcode: https://oj.leetcode.com/problems/balanced-binary-tree/
//60 ms Accepted
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//SECOND TRIAL
class Solution {
private:
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
public:
    bool isBalanced(TreeNode *root) {
        if(!root)
            return true;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
