//Same withe leetcode: https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//60ms
//My Leetcode solution: https://github.com/kunth/Leetcode/blob/master/Leetcode_convert-sorted-array-to-binary-search-tree.cc
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* construct_tree(TreeNode* root, vector<int>& num, int begin, int end)
    {
        if(begin > end)
            return NULL;
        int mid = (begin+end)/2;
        root = new TreeNode(num[mid]);
        root->left = construct_tree(root->left, num, begin, mid-1);
        root->right = construct_tree(root->right, num, mid+1, end);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return construct_tree(NULL, num, 0, num.size()-1);
    }
};

