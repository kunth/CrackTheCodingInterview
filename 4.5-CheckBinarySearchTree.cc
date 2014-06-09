//Same with Leetcode: https://oj.leetcode.com/problems/validate-binary-search-tree/
//My Leetcode address: https://github.com/kunth/Leetcode/blob/master/Leetcode_validate-binary-search-tree.cc

#include<cstdio>
using namespace std;
//Solution 1, from Leetcode

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

//Solution 2, from the book's solution
//80ms
class Solution2 {
private:
    bool isValid(TreeNode *root, int left, int right)
    {
        if(!root)
            return true;
        if(left < root->val && root->val < right)
            return isValid(root->left, left, root->val) && isValid(root->right, root->val, right);
        else
            return false;
    }
public:
    bool isValidBST(TreeNode *root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};

//abandon testing since accepted by Leetcode.
int main()
{
  return 0;
}
