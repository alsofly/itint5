/*
树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  TreeNode *left;
  TreeNode *right;
}*/


bool isBalanced_withHeight(TreeNode *root, int& height)
{
    if ( root == NULL )
    {
        height = 0;
        return true;
    }
    
    int leftHeight, rightHeight;
    if ( !isBalanced_withHeight(root->left, leftHeight) ) return false;
    if ( !isBalanced_withHeight(root->right, rightHeight) ) return false;
    
    height = max(leftHeight, rightHeight) + 1;
    return abs(leftHeight - rightHeight) < 2;
}

bool isBalancedTree(TreeNode *root) {
    int height;
    return isBalanced_withHeight(root, height);
}