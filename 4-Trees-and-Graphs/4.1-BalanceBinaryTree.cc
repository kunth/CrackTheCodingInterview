//Same with Leetcode: https://oj.leetcode.com/problems/balanced-binary-tree/
//60 ms Accepted
//My Leetcode solution: https://github.com/kunth/Leetcode/blob/master/Leetcode_balanced-binary-tree.cc
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//SECOND TRIAL, 60ms
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

//Third Trial, 88ms, unbelievalbe, slower than last one
class Solution {
private:
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        int lh = getHeight(root->left);
        if(lh == -1)
            return -1;
        int rh = getHeight(root->right);
        if(rh == -1)
            return -1;
        if(abs(lh-rh)>1)
            return -1;
        return 1 + max(lh, rh);
    }
public:
    bool isBalanced(TreeNode *root) {
        if(getHeight(root)==-1)
            return false;
        return true;
    }
};

//abandon testing since accepted by Leetcode.
