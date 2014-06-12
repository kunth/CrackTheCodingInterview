#include<cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p)
            return !q;
        else if(!q)
            return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    //check whether q is the node of p
    TreeNode* hasKey(TreeNode *p, TreeNode *q)
    {
      if(!p || !q)
        return false;
      if(p->val==q->val)
        return p;
      else if(q->val < p->val)
        return hasKey(p->left, q);
      else
        return hasKey(p->right, q);
    }

public:
    bool isSubtree(TreeNode *p, TreeNode *q)
    {
      TreeNode* t = hasKey(p, q);
      if(t)
        return isSameTree(t, q);
      return false;
    }
};

//without testing, currently
int main()
{
  return 0;
}
