/*树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  TreeNode *left, *right;
  bool isLeftThread, isRightThread;
}*/
TreeNode *traverse(TreeNode *root, TreeNode *pre)
{
   if ( root->left )
   {
      TreeNode *last = traverse(root->left, pre);
      last->right = root;
      last->isRightThread = true;
   }
   else if ( pre )
   {
      root->left = pre;
      root->isLeftThread = true;
   }

   TreeNode *last;
   if ( root->right )
   {
      last = traverse(root->right, root);
   }
   else
   {
      last = root;
   }
   return last;
}

void convertToThreadedTree(TreeNode *root) {
   if ( root == NULL ) return;
   traverse(root, NULL);
}