#include<cstdio>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isInSubtree(TreeNode* root, TreeNode* t)
{
  if(!root)
    return false;
  if(root == t)
    return true;
  else
    return isInSubtree(root->left, t) || isInSubtree(root->right, t);
}

TreeNode* FindFirstAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
  if(!root)
    return NULL;
  if(root==p || root==q)
    return root;
  bool f1 = isInSubtree(root->left, p);
  bool f2 = isInSubtree(root->right, q);
  if(f1 == f2)
    return root;
  //both on the left substree
  if(f1)
    return FindFirstAncestor(root->left, p, q);
  else
    return FindFirstAncestor(root->right, p, q);
}

TreeNode* Find(TreeNode* root, TreeNode*p, TreeNode*q)
{
  if(!isInSubtree(root, p) || !isInSubtree(root, q))
    return NULL;
  return FindFirstAncestor(root, p, q);
}

//without testing
int main()
{
  return 0;
}
