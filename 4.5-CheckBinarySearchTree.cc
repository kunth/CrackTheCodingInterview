//Same with Leetcode: https://oj.leetcode.com/problems/validate-binary-search-tree/
//My Leetcode address: https://github.com/kunth/Leetcode/blob/master/Leetcode_validate-binary-search-tree.cc

class Solution {
private:
    vector<int>vec;
    void InOrder(TreeNode *root)
    {
        if(!root)
            return;
        InOrder(root->left);
        vec.push_back(root->val);
        InOrder(root->right);
    }
public:
    bool isValidBST(TreeNode *root) {
        InOrder(root);
        for(int i = 0; i<(int)vec.size()-1; ++i)
            if(vec[i] >= vec[i+1])
                return false;
        return true;
    }
};
