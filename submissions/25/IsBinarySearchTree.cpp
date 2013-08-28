/*
树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  int val;
  TreeNode *left, *right;
}*/

bool isBST_ext(TreeNode *root, int& small, int& big)
{
    int leftBig(root->val), rightSmall(root->val + 1);
    if ( root->left == NULL ) small = root->val;
    else if ( !isBST_ext(root->left, small, leftBig) ) return false;
    if ( root->right == NULL ) big = root->val;
    else if ( !isBST_ext(root->right, rightSmall, big) ) return false;
    
    if ( root->val < leftBig || root->val >= rightSmall ) return false;
    return true;
}

bool isBST(TreeNode *root) {
    if ( root == NULL ) return true;
    int small, big;
    return isBST_ext(root, small, big);
}